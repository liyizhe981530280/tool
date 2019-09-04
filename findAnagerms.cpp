/*************************************************************************
  > File Name: findAnagerms.cpp
  > Author: liyz
  > Mail: 981530280@qq.com 
  > Created Time: 2019年08月10日 星期六 08时45分18秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	public:
		vector<int> findAnagrams(string s, string p)
		{
			vector<int> res;
			if(s.empty() || s.size() < p.size())
			{
				return res;
			}

			int left = 0;
			int right = p.size() - 1;
			int freqS[26] = {0};
			int freqP[26] = {0};

			for(int i = 0; i < p.size();i++)
			{
				freqS[(int)s[i] - (int)'a']++;
				freqP[(int)p[i] - (int)'a']++;
			}

			while(right < s.size())
			{
				int  i = 0;
				for(;i < 26; i++)
				{
					if(freqS[i] != freqP[i])
					{
						break;
					}
				}

				if(i == 26)
				{
					res.push_back(left);
				}
				if(right + 1 == s.size())
				{
					return res;
				}
				freqS[(int)s[left] - (int)'a']--;
				freqS[(int)s[right + 1] - (int)'a']++;
				left++;
				right++;
			}
			return res;
		}
};

int main()
{
	string s = "cbaebabacd";
	string p = "abc";
	Solution a;
	vector<int> res;
	res = a.findAnagrams(s,p);
	for(int i = 0;i < res.size();i++)
	{
		cout<< res[i];
	}
	printf("\n");
	return 0;
}
