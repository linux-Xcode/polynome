#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

int calc_n(std::string polynome)
		{
			int n=0;
			for(int i=0; i<(int)polynome.size(); ++i)
				{
					if(polynome[i] == '+' || polynome[i] == '-')
						n++;
				}
			return n;
		}
void def(std::string OUT[],std::string operations[] ,std::string polynome)
		{
			int ctr=0;
			for(int i=0; i<(int)polynome.size(); ++i)
				{
					if(polynome[i] == '+' || polynome[i] == '-')
						{
                            operations[ctr]=polynome[i];
							ctr++;
							continue;
						}
					else OUT[ctr]+=polynome[i];
				}
		}
int N(std::string term)
    {
        std::string n;
        std::size_t s;
        if(term.find("^")==std::string::npos)
        {
        	if(term.find("x")!=std::string::npos || term.find("X")!=std::string::npos)
        	return 1;
        	else return 0;
        }
        else
        	{
        		for(int i=int(term.size())-1; i>=0; i--)
            		{
                		if(term[i] == '^')
                    		break;
                		else
                    	n+=term[i];
            		}
        		std::string m;
        		for(int c=int(n.size())-1; c>=0; c--) m+=n[c];
        		return int(std::stof(m, &s));
        	}
    }


float An(std::string term)
	{
		std::string a;
		std::size_t s;
		if(term[0] == 'x' || term[0] == 'X')
			return 1;
		else
			{
                for(int i=0; i<(int)term.size(); i++) {
                        if(term[i] == 'x' || term[i] == 'X') break; else a+=term[i];
                }
		return std::stof(a, &s);
	}
}


float POL(std::string P, float X)
	{
		int n=calc_n(P);
		std::string terms[n+1];
		std::string op[n];
		def(terms, op, P);
		float result=An(terms[0])*pow(X, N(terms[0]));
		int i=1; while(i<n+1)
			{
				if(op[i-1].find("+")!=std::string::npos) result+= An(terms[i])*pow(X,N(terms[i]));
				else if(op[i-1].find("-")!=std::string::npos) result -= An(terms[i])*pow(X,N(terms[i]));
                i++;
			}
		return result;
	}
float sol(std::string Equation, float a, float b, float e)
	{
		float epsilon = b-a;
		while(abs(epsilon) > e)
		{
			float c=(b-a)/2;
			if(POL(Equation, b)*POL(Equation, c) > 0) b=c;
			else if(POL(Equation, a)*POL(Equation, c) > 0) a=c;
			else if(POL(Equation, c)==0) {break; return c;}
		}
		return b;
	}
int main(int argc, char* argv[])
    {
        std::string p="x^2-4x+3";
        std::cout << POL(p, 1) << std::endl;
        return 0;
    }
