#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

class CashRegister
{
    public:

        CashRegister(double rate);

        void reset_sales();
        void add_item(double price);
        void add_taxable_item(double price);
        double get_total_tax();
        void display_total_tax();
        double get_sales_total() const;
        int get_sales_count() const;
    private:
        vector<double> itemPrices;
        double tax_rate;
        double tax_total;
        double tax_item;
};

CashRegister::CashRegister(double rate)
{
    tax_rate = rate;
    tax_total = 0.00;
    tax_item = 0.00;
    itemPrices.clear();
}

void CashRegister::reset_sales()
{
    tax_total = 0.00;
    tax_item = 0.00;
    itemPrices.clear();
}

void CashRegister::add_item(double price)
{
    itemPrices.push_back(price);
}

double CashRegister::get_sales_total() const
{
    return accumulate(itemPrices.begin(), itemPrices.end(), tax_total);
}

int CashRegister::get_sales_count() const
{
   return itemPrices.size(); 
}
void CashRegister::add_taxable_item(double price)
{
    tax_item = tax_item + price;
    itemPrices.push_back(price);
}
double CashRegister::get_total_tax()
{
    tax_total = tax_total + (tax_item * (tax_rate / 100));
    tax_item = 0.00;
    return tax_total;
}

void display(CashRegister& reg)
{
    cout << "Item " << reg.get_sales_count() << ": $" << fixed << setprecision(2) << reg.get_sales_total() << "\t\tInclude tax: $" << reg.get_total_tax() << endl;
}

int main()
{
    CashRegister register1(5);
    register1.add_item(100);
    display(register1);
    register1.add_item(200);
    display(register1);
    register1.add_item(200);
    display(register1);
    register1.add_taxable_item(100);
    display(register1);
    register1.add_taxable_item(200);
    display(register1);

    cout << endl;
    register1.reset_sales();

    register1.add_item(100);
    display(register1);
    register1.add_item(100);
    display(register1);
    register1.add_item(200);
    display(register1);
    register1.add_taxable_item(200);
    display(register1);
    register1.add_taxable_item(300);
    display(register1);
    return 0;
}