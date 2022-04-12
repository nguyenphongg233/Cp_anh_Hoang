/*
  Link Problem : 
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;




int l, r;
int f[20][2][2][3][3][3][3][3][3][3][3][3][3];
int predig = 0;
 
int cal(string s, int i, bool ok, int start, int ko, int mot, int hai, int ba, int bon, int nam, int sau, int bay, int tam, int chin)
{
	if(i == (int)s.size()) return 1;
	if(f[i][ok][start][ko][mot][hai][ba][bon][nam][sau][bay][tam][chin] != -1) return f[i][ok][start][ko][mot][hai][ba][bon][nam][sau][bay][tam][chin];
	int res = 0;
 
	if(i > 0 && start == 0) 
	{
		if(predig == 0) ko--;
		else start = 1;
	}
 
	int ub = 9;
	if(ok) ub = s[i]-'0';
	for(int dig = 0; dig <= ub; dig++)
	{
		if(dig == 0)
		{
			if(ko < 2) 
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko+1, mot, hai, ba, bon, nam, sau, bay, tam, chin);
			}	
			else continue;
		}
		if(dig == 1)
		{
			if(mot < 2) 
			{
				predig = 1;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot+1, hai, ba, bon, nam, sau, bay, tam, chin);
			}
			else continue;
		}
		if(dig == 2)
		{
			if(hai < 2) 
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot, hai+1, ba, bon, nam, sau, bay, tam, chin);
			}
			else continue;
		}
		if(dig == 3)
		{
			if(ba < 2) 
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot, hai, ba+1, bon, nam, sau, bay, tam, chin);
			}
			else continue;
		}
		if(dig == 4)
		{
			if(bon < 2) 
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot, hai, ba, bon+1, nam, sau, bay, tam, chin);
			}
			else continue;
		}
		if(dig == 5)
		{
			if(nam < 2) 
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot, hai, ba, bon, nam+1, sau, bay, tam, chin);
			}
			else continue;
		}
		if(dig == 6)
		{
			if(sau < 2)
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot, hai, ba, bon, nam, sau+1, bay, tam, chin);
			}
			else continue;
		}
		if(dig == 7)
		{
			if(bay < 2) 
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot, hai, ba, bon, nam, sau, bay+1, tam, chin);
			}
			else continue;
		}
		if(dig == 8)
		{
			if(tam < 2) 
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot, hai, ba, bon, nam, sau, bay, tam+1, chin);
			}
			else continue;
		}
		if(dig == 9)
		{
			if(chin < 2) 
			{
				predig = dig;
				res += cal(s, i+1, ok & (dig==ub), start, ko, mot, hai, ba, bon, nam, sau, bay, tam, chin+1);
			}
			else continue;
		}
	}
	return f[i][ok][start][ko][mot][hai][ba][bon][nam][sau][bay][tam][chin] = res;
}
 
int32_t main()
{
 
	cin >> l >> r;
	l--;
	string R = to_string(r);
	string L = to_string(l);
	memset(f, -1, sizeof(f));
	int A = cal(R, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	memset(f, -1, sizeof(f));
	int B = cal(L, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
 
	cout << A-B;
 
	return 0;
}