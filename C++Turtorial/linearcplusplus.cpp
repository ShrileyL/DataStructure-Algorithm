#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n(0);
	double x, y, sumx(0),sumy(0),sumxy(0),sumx2(0);
	double m,b;
    string filenamein;
    
	ifstream fin;
	
	cout << "please enter the name of the input file: "<< endl;
	cin >> filenamein;

	//cout << "enter the name of the output file: " << endl;
	//cin >> filenameout;

	fin.open(filenamein.c_str());

	if (fin.fail())
	{
		cerr << "fail in open\n ";
		exit(1);
		/* code */
	}

	fin >> x >> y;
	while(!fin.eof())
	{
		n++;
		sumx += x;
		sumy += y;
		sumx2 += x*x;
		sumxy += x*y;
		fin >> x >> y;
	}
	cout << "cout=" << n << "sumx=" << sumx <<" sumy=" << sumy <<endl;
	cout <<" sumxy=" << sumxy << " sumx2=" << sumx2 <<endl;

	m = ((sumx*sumy)-n*sumxy)/(sumx*sumx-n*sumx2);
	b = (sumx*sumxy-sumx2*sumy)/(sumx*sumx-n*sumx2);

	cout << "Linear model: \n";
    cout << "ozone-mix-ratio = " << m << " altitude + "
    << b << endl;

    fin.close();
	return 0;
}