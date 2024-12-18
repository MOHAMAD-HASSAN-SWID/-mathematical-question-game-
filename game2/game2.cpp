
#include <iostream>
#include <cmath>
#include <string>
#include<set>
#include<cstdlib>
#include<time.h>
#include<algorithm>
#include<math.h>
using namespace std;
enum level_game
{
	esy =1 , normal = 2 , hard = 3
};
string level_game_arr[3] = { "esy","normal","hard" };
enum type_game
{
	add= 1, sub = 2, mul = 3, diav = 4, mix = 5
};
string type_game_arr[5] = { "add","sub","mul","diav","mix" };
struct game
{
	level_game level;
	type_game type;
};
struct number
{
	int num1;
	int num2;
	int ans;
};
struct player
{
	int player_answer;
	int scor_player=0;
};
int rand_num(game gg)
{
	if (gg.level == esy)
		return (rand() % 10)+1;
	else if (gg.level == normal)
		return (rand() % 50)+1;
	else
		return (rand() % 100)+1;
}
int rand_ch()
{
	return  (rand() % 4) + 1;
}
void answar(game & gg, number & num)
{
	if (gg.type == mix)
		gg.type = type_game(rand_ch());
	 if (gg.type == add)
		 num.ans = num.num1 + num.num2;
	else if (gg.type == sub)
		 num.ans = num.num1 - num.num2;
	else if (gg.type == mul)
		 num.ans = num.num1 * num.num2;
	else if (gg.type == diav)
		 num.ans = num.num1 / num.num2;
}
void secren(game gg,number num)
{
	cout << num.num1<<endl;
	if (gg.type == 1)
		cout << "+";
	else if (gg.type == 2)
		cout << "-";
	else if (gg.type == 3)
		cout << "*";
	else if (gg.type)
		cout << "/";
	cout << endl << num.num2;
}
void secren_ans( number num,player & pl)
{
	
	if (pl.player_answer == num.ans)
	{
		pl.scor_player++;
		cout << "------";
	}
	else
	{
		cout <<"the right answer is : " <<num.ans << endl;
		cout << "------";
	}
}
void end_game(player pl,int qus)
{
	cout << "\t\t___________________";
	if (pl.scor_player >= (qus / 2)+1)
	{
		system("color 2F");
		cout << "YOU ARE PASS";
	}
	else
	{
		system("color 4F");
		cout << "\aYOU ARE fail";
	}
	cout << "\t\t___________________";

}

void secren_end(game gg, player pl,int qus)
{
	cout << "\n\t\t**********************\n";
	cout << "\t\tlevel : " <<level_game_arr[ gg.level-1];
	cout << "\n\t\ttype : " << type_game_arr[gg.type - 1];
	cout << "\n\t\trigt answer is :" << pl.scor_player;
	cout << "\n\t\twrong asnwer is :" << qus - pl.scor_player;
	cout << "\n\t\t**********************\n";
}
void tahdir(game &gg,int& n)
{
	cout << "what is leavel you want : esy =1  ,  normal =2  ,  hard=3 : ";
	cin >> n;
	gg.level = level_game(n);
	cout << "what tayp is you want  :  add =1  ,  sub =2  ,  mul =3  ,  div =4  ,   mix =5 : ";
	cin >> n;
	gg.type = type_game(n);
}
void  start_game (int qus)
{
	
	game gg;
	number num;
	player pl;
	int n;
	tahdir(gg,n);
	for (int i = 0; i < qus; i++)
	{
		num.num1 = rand_num(gg);
		num.num2 = rand_num(gg);
		answar(gg, num);
		secren(gg, num);
		cout << "\n_______________\n";
		cin >> pl.player_answer;
		secren_ans(num, pl);
		cout << endl;
		gg.type = type_game(n);
	}
	end_game(pl,qus);
	secren_end(gg, pl, qus);
}
int main()
{
	srand((unsigned)time(NULL));
	char y = 'y';
	while (y == 'y')
	{
		system("cls");
		system("color 0F");
		int qustions;
		cout << "how many qustions ypu want : ";
		cin >> qustions;
		start_game(qustions);
		cout << "\n\t\t\t do you want play agine y/n : ";
		cin >> y;
	}
}

