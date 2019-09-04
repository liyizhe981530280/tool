#include <iostream>
#include <string>
#include <valarray>

class Student{
	private:
		typedef std::valarray<double> ArrayDb;
		std::string name;
		ArrayDb scores;
		std::ostream & arr_out(std::ostream & os)const;
	public:
		Student() : name("Null Student"),scores() {}
		explicit Student(const std::string & s) : name(s), scores() {}
		explicit Student(int n) : name("Nully"), scores(n) {}
		Student(const std::string & s, const ArrayDb & a)
			:name(s),scores(a){}
		Student(const char *str, const double *pd, int n)
			:name(str),scores(pd, n) {}
		~Student() {}
		double Average() const;
		const std::string & Name() const;
		double & operator[] (int i);
		double operator[](int i) const;
		friend std::istream & operator>>(std::istream & is, Student & stu);
		friend std::istream & getline(std::istream & is, Student & stu);
		friend std::ostream & operator>>(std::ostream & os, Student & stu);
};

using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::Average() const
{
	if(scores.size() > 0) 
		return scores.sum()/scores.size();
	else
		return 0;
}

const string & Student::Name() const
{
	return name;
}

double & Student::operator[] (int i)
{
	return scores[i];
}
double Student::operator[] (int i) const
{
	return scores[i];
}

ostream & Student::arr_out(ostream & os) const
{
	int i;
	int lim = scores.size();
	if(lim > 0)
	{
		for(i = 0; i < lim; i++)
		{
			os<<scores[i] << "";
			if(i % 5 == 4)
				os << endl;
		}
		if(i % 5 != 0)
			os<< endl;
	}else
		os<< "empty array";
	return os;
}

istream & operator>>(istream & is, Student & stu)
{
	is >> stu.name;
	return is;
}

istream & getline(istream & is , Student & stu)
{
	getline(is, stu.name);
	return is;
}

using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
	int i;
	for(i = 0;i < pupils; ++i)
		set(ada[i], quizzes);
	cout<< "\nStudent List :\n";
	for(i = 0; i < pupils; ++i)
		cout<<ada[i].Name() << endl;
	cout<<"\nResults:";
	for(i = 0; i < pupils; ++i)
	{
		cout<< ada[i] <<endl;
		cout<<"average: "<< ada[i].Average() <<endl;
	}

	cout<<"Done\n";
	return 0;
}

void set(Student & sa, int n)
{
	cout<<"please enter the student's name:" ;
	getline(cin, sa);
	cout<<"please enter "<< n << "quiz scores:\n";
	for(int i = 0; i < n; i++)
		cin>>sa[i];
	while(cin.get() != '\n')
		continue;
}
ostream & operator<<(ostream &os, const Student & stu)
{
	os << "Scores for "<< stu.name <<":\n"; 
	stu.arr_out(os);
	return os;
}



