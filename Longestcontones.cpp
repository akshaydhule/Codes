/* longest contineous sequence of ones and zeros


std::vector<int> longestlist(vector<int> a, int availflips)
{
	vector<int> current;
	vector<int> max;
	int currones=0;
	int maxones =0;
	int flips=0;
	bool val;
	for(int i=0;i<a.size();i++)
	{
		val = a[i];
		if(val ==1)
		{
			currones++;
			
		}
		else
		{
			if(flips<=availflips)
			{
				current.push_back(i);
				flips++;
				currones++;
			}
			else
			{
				if(currones>maxones)
				{
					max = current;
					maxones = currones;
				}
				else
				{
					currones =1;
					current.clear();
					current.push_back(i);
					flips =1;
				}
			}
		}
	}
	if(currones>maxones)
	{
		max = current;
	}
	return max;
}
