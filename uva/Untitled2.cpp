#include<iostream>

using namespace std;

class data
{
    string prod_name;
    int prod_id;
public:
    void set_name(string name);
    void set_id(int i);
    void show();
};

inline void  data::set_name(string name)
{
    this->prod_name = name;
}

inline void  data::set_id(int i)
{
    this->prod_id = i;
}

void data::show()
{
    cout << "Product Name : " << prod_name << endl;
    cout << "Product id : " << prod_id << endl;
}
class Data : public data
{
    static double sum;
    int number_of_prod;
    double selling_price,total_price;
public:
    Data(){};
    ~Data(){}
    void set(double sell);
    void set(int num);
    void set();
    void showInf();
    friend void totalSell(Data ob);
};

double Data::sum;
void Data::set(int num)
{
    number_of_prod = num;
}

void Data::set(double sell)
{
    selling_price = sell;
}

void Data::set()
{
    total_price = number_of_prod*selling_price;
    cout << total_price << endl;
    sum = sum+total_price;
}

void Data::showInf()
{
    this->show();
    cout << "Number : " << number_of_prod << endl;
    cout << "total price : " << selling_price << endl;
    cout << "total price : " << total_price << endl;
}

void totalSell(Data ob)
{
    cout << "Total : " << ob.sum << endl;
}
int main()
{
    Data product[100];
    int n,i,tmp;
    double x;
    string s;
    cout << "How many kinds of product : " ;
    cin >> n ;
    for(i=0;i<n;i++)
    {
        cout << "Product Name : ";
        cin >> s ;
        product[i].set_name(s);
        cout << "Product ID : ";
        cin >> tmp;
        product[i].set_id(tmp);
        cout << "number of sell : ";
        cin >> tmp;
        product[i].set(tmp);
        cout << "Selling price : ";
        cin >> x;
        product[i].set(x);
        product[i].set();
        cout << endl;
    }

    for(i=0;i<n;i++)
    {
        product[i].showInf();
        cout << endl;
    }
    totalSell(product[0]);
    return 0;
}

