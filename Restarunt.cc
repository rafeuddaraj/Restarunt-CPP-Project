#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    void set_total_tax(double total_txt)
    {
        this->total_tax += total_txt;
    }
    double get_total_txt()
    {
        return this->total_tax;
    }
    Restaurant()
    {
        this->total_tax = 0.0;
    }

private:
    double total_tax;
};
void input_food(Restaurant *restaurant, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> restaurant->food_item_codes[i];
        getchar();
        getline(cin, restaurant->food_item_names[i]);
        cin >> restaurant->food_item_prices[i];
    }
}
void make_bill(Restaurant *restaurant, int n)
{
    cout << endl;
    cout << "\t\t\t\t\t MAKE BILL " << endl;
    cout << "\t\t\t\t ____________________________" << endl;
    cout << endl
         << endl;
    cout << "Item Code\t\tItem Name\t\t\t\tItem Price" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << restaurant->food_item_codes[i] << "\t\t\t" << restaurant->food_item_names[i] << "\t\t\t" << restaurant->food_item_prices[i] << endl;
    }
}
int search_food(Restaurant *restaurant, int item_code, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (restaurant->food_item_codes[i] == item_code)
        {
            return i;
        }
    }
    return -1;
}

void bill_summery(Restaurant *restaurant, int item, int *quantity, int *item_code, int n, int table)
{
    bool is_done = false;
    int total_price = 0;
    double tax;
    for (int i = 0; i < item; i++)
    {
        int index = search_food(restaurant, item_code[i], n);
        if (index < 0)
        {
            is_done = true;
        }
        else
        {
            is_done = false;
        }
    }
    if (!is_done)
    {
        cout << endl
             << endl;
        cout << "\t\t\t\t\t\tBILL SUMMARY " << endl;
        cout << "\t\t\t\t\t_________________________________" << endl;
        cout << endl;
        cout << "Table No : " << table << endl;
        cout << "Item Code \t\t"
             << "Item Name \t\t\t"
             << "Item Price\t\t"
             << "Item Quantity\t\t"
             << "Total Price" << endl;
        for (int i = 0; i < item; i++)
        {
            int index = search_food(restaurant, item_code[i], n);
            if (index >= 0)
            {
                total_price += quantity[i] * restaurant->food_item_prices[index];
                cout << restaurant->food_item_codes[index] << "\t\t\t" << restaurant->food_item_names[index] << "\t\t" << restaurant->food_item_prices[index] << "\t\t\t" << quantity[i] << "\t\t\t" << restaurant->food_item_prices[index] * quantity[i] << endl;
                tax = double(double(total_price)) * double(5) / double(100);
                restaurant->set_total_tax(tax);
            }
        }
    }
    else
    {
        cout << "This code is not valid, he/she needs to enter the code again." << endl;
        return;
    }
    cout << "Tax\t\t\t\t\t\t\t\t\t\t\t\t\t" << tax << endl;
    cout << "_____________________________________________________________________________________________________________________" << endl;
    cout << "NET TOTAL\t\t\t\t\t\t\t\t\t\t\t\t" << double(total_price + tax) << endl;
}
void customer_input(Restaurant *restaurant, int n)
{
    int item, table;
    int quantity[12], item_code[12];
    cout << "Enter Table No : ";
    cin >> table;
    cout << "Enter Number of Items : ";
    cin >> item;
    for (int i = 0; i < item; i++)
    {
        cout << "Enter Item " << i + 1 << " Code : ";
        cin >> item_code[i];
        cout << "Enter Item " << i + 1 << " Quantity : ";
        cin >> quantity[i];
    }
    bill_summery(restaurant, item, quantity, item_code, n, table);
}
int main()
{
    int n;
    cin >> n;
    Restaurant *restaurant = new Restaurant();
    input_food(restaurant, n);
    make_bill(restaurant, n);
    while (true)
    {
        customer_input(restaurant, n);
    }
    return 0;
}