#include <iostream>
#include <string>
using namespace std;

class TableTennisPlayer{
	private:
		string firstname;
		string lastname;
		bool hasTable;
	public:
		TableTennisPlayer(const string & fn = "none", 
				const string & ln = "none", bool ht = false);
		void Name() const;
		bool HasTable() const {return hasTable;};
		void ResetTable(bool v) {hasTable = v;};

};

TableTennisPlayer::TableTennisPlayer(const string & fn,
				const string & ln , bool ht): firstname(fn),lastname(ln),
               hasTable(ht){}
TableTennisPlayer::TableTennisPlayer(const string &fn, const string & ln, bool ht)
{
	firstname = fn;
	lastname = ln;
	hasTable = ht;
}

void TableTennisPlayer::Name() const
{
	
	const string b = "dd";
	string c = b;
	b = const_cast<string> (lastname); 
	std::cout<< lastname << "," << firstname << ","<< hasTable <<std::endl;
}

class RatedPlayer:public TableTennisPlayer{
	private:
		unsigned int rating;
	public:
		RatedPlayer(unsigned int r = 0, const string & fn = "none",
				 const string & ln = "none", bool ht = false);
		RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
		unsigned int Rating() const { return rating; }
		void ResetRating(unsigned int r) {rating = r; }
};

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, 
		const string &ln, bool ht):TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) :
	TableTennisPlayer(tp), rating(r)
{

}

int main()
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Chunk", "Blizzard",true);
//	TableTennisPlayer player2("Tara", "Boomdea",false);

	RatedPlayer rplayer1(1140, "Mallory","Duck", true);

	player1.Name();
//	player2.Name();

	rplayer1.Name();

	cout<< "Rating :" << rplayer1.Rating() << endl;

	RatedPlayer rplayer2(1122, player1);
	cout<< "Name: ";

	rplayer2.Name();
	cout<<":Rating: " << rplayer2.Rating() << endl;

/*	if(player1.HasTable())
		cout<<":has a table \n";
	else
		cout<<":hasn't a table \n";


	if(player2.HasTable())
		cout<<":has a table \n";
	else
		cout<<":hasn't a table \n";

		*/
	return 0;
}


