#include<bits/stdc++.h>

using namespace std;

class Box {
private:
    int l;
    int b;
    int h;
public:

    Box() {
        l = 0;
        b = 0;
        h = 0;
    }

    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }

    Box(Box const &box) {
        l = box.l;
        b = box.b;
        h = box.h;
    }

    int getLength() {
        return l;
    }

    int getBreadth() {
        return b;
    }

    int getHeight() {
        return h;
    }

    long long CalculateVolume() const {
        return ((long long) l) * b * h;
    }

    bool operator < (Box &other) const {
        if (l != other.l) {
            return l < other.l;
        } else if (b != other.b) {
            return b < other.b;
        }
        return h < other.h;
    }

    friend ostream& operator << (ostream& output, const Box& B) {
        output << B.l << " " << B.b << " " << B.h;
        return output;
    }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
