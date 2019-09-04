#include <iostream>
#include <string>
using namespace std;
class AcctABC
{
  private:
	std::string fullName;
	long acctNum;
	double balance;

  protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string &FullName() const { return fullName; }
	long AcctNum() const { return acctNum; }
	Formatting SetFormat() const;
	void Restore(Formatting &f) const;

  public:
	AcctABC(const std::string &s = "Nullbody", long an = -1, double baf = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;
	double Balance() const { return balance; };
	virtual void ViewAcct() const = 0;
	virtual ~AcctABC() {}
};

class Brass : public AcctABC
{
  public:
	Brass(const std::string &s = "Nullbody", long an = -1,
		  double bal = 0.0) : AcctABC(s, an, bal) {}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};
class BrassPlus : public AcctABC
{
  private:
	double maxLoan;
	double rate;
	double owesBank;

  public:
	BrassPlus(const std::string &s = "Nullbody", long an = -1,
			  double bal = 0.0, double ml = 500,
			  double r = 0.10);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

AcctABC::AcctABC(const string &s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative dpeposit not allowed;"
			 << "deposit  is canceled \n";
	else
		balance += amt;
}

void AcctABC::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Negtive deposit not allowed;"
			 << "deposit is cancelled \n";
	else
		balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting &f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}
void Brass::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Withrawal amount must be postive;"
			 << "withrawal canceled \n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Withdrawal amount of $" << amt
			 << "exceeds yours balance \n"
			 << "Withdrawal canceled \n";
}

void Brass::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Brass Client: " << FullName() << endl;
	cout << "Account Number:" << AcctNum() << endl;
	cout << "Balance: $" << Balance() << endl;
	Restore(f);
}

BrassPlus::BrassPlus(const string &s, long an, double bal, double ml,
					 double r) : AcctABC(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	Formatting f = SetFormat();

	cout << "BrassPlus Client: " << FullName() << endl;
	cout << "Accout Number: " << AcctNum() << endl;
	cout << "Balance:$ " << Balance() << endl;
	cout << "Maximum loan: $ " << maxLoan << endl;
	cout << "Owed to bank: $ " << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * rate << endl;
	Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f = SetFormat();

	double bal = Balance();
	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance: $ " << advance << endl;
		cout << "Finance charge: $ " << advance * rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled \n";
	Restore(f);
}

const int CLIENTS = 4;

int main()
{

	AcctABC *p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name:";
		getline(cin, temp);
		cout << "Enter client's account number :";
		cin >> tempnum;
		cout << "Enter 1 for Brass Account or :"
			 << "2 for BrassPlus Account: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2 :";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit:$ ";
			cin >> tmax;
			cout << "Enter the interest rate "
				 << "as a decimal fraction :";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
										 tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
	cout << "Done.\n";
	return 0;
}
