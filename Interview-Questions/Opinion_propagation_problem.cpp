/*
//============================================================================
// Name        : promoter_medallia.cpp (Opinion propagation method)
// Description : Given Persons list
1. if threshold is 0 then person is promoter
2. if threshold is 1 then person can not be promoter
3. if threshold is b/w 0 and 1 then the person can be promoter
if proportion of its promoter parents is atleast threshold

return the list of promoters
//============================================================================
*/
#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Person {
private:
	string name;
	double threshold;
	vector<Person *> influencedBy;
	bool promoter;
public:
	Person(string name, double threshold) {
		this->name = name;
		this->threshold = threshold;
		this->promoter = threshold == 0.0;
	}

	string getName() {
		return this->name;
	}
	double getThreshold() {
		return this->threshold;
	}
	vector<Person *> getInfluencedBy() {
		return this->influencedBy;
	}
	void addInfluencer(Person *p) {
		influencedBy.push_back(p);
	}
	bool isPromoter() {
		return this->promoter;
	}
	void setPromoter(bool promoter) {
		this->promoter = promoter;
	}
};

struct PersonCompare {
  bool operator()(Person* p1, Person* p2) {
    return p1->getName().compare(p2->getName());
  }
};


/*
 * @return A subset of the given people who are promoters
 */
void setpromote(Person *child)
{
	int count =0;
	vector<Person *> influencers =child->getInfluencedBy();
	if(child->isPromoter() || child->getThreshold() == 1.0)
			return;
	for(int i=0;i<influencers.size();i++)
	{
		if(influencers[i]->isPromoter() == true)
			count++;
	}
	if((count/influencers.size()) >= child->getThreshold())
		child->setPromoter(true);
}

void checkforparents(Person * child, vector<Person *> parents)
{
	if(child->isPromoter())
		return;
	for(int j=0;j<parents.size();j++)
	{
		vector<Person *> influencers =parents[j]->getInfluencedBy();
		if(influencers.size()>0)
		{
			vector <Person *> grandparents = parents[j]->getInfluencedBy();
			checkforparents(parents[j],grandparents);
		}
	}
	setpromote(child);
}
vector<Person *> findPromoters(vector<Person *> people) {
    vector<Person *> promoters, parents;
    stack<Person *> persons;
    for(int i=0;i<people.size();i++)
    {
    	vector<Person *> influencers =people[i]->getInfluencedBy();
    	if(influencers.size()>0)
		{
			vector <Person *> parents = people[i]->getInfluencedBy();
			checkforparents(people[i],parents);
		}
    }
    for(int i=0;i<people.size();i++)
	{
		if(people[i]->isPromoter())
			 promoters.push_back(people[i]);
	}
    return promoters;
}

int main() {
	Person alice("alice", 0.5);
	Person bob("bob", 0.0);
	Person Mark("Mark", 0.5);
	Person gen("gen", 0.6);
	alice.addInfluencer(&bob);
	gen.addInfluencer(&Mark);
	//alice.addInfluencer(&Mark);
	vector<Person *> people, Promoters;
	people.push_back(&alice);
	people.push_back(&bob);
	people.push_back(&Mark);
	people.push_back(&gen);
	Promoters = findPromoters(people);
	for(int i = 0;i<Promoters.size();i++)
		cout<<Promoters[i]->getName()<<"\n";
	return 0;
}
