#include <iostream>
#include <set>

using namespace std;

struct Order
{
    int order_id;
    int code;
    double price;
    int quantity;
    char type;
    Order() : order_id {} {}
    Order(int id, int stock, double p, int qty, char s) : order_id(id), code(stock), price(p), quantity(qty), type(s) {}

    void show()
    {
        printf("orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: %c\n",
                order_id, code, price, quantity, type);
    }
};
struct OrderEntry
{
    int order_id;
    double price;
    char type;

    bool operator<(const OrderEntry &other) const
    {
        if (price != other.price)
        {
            if (type == other.type)
                return type == 'b' ? price > other.price : price < other.price;
            return type < other.type;
        }
        if (order_id != other.order_id)
            return order_id < other.order_id;
        return type < other.type;
    }
};

set<OrderEntry> buy_orders[10005];
set<OrderEntry> sell_orders[10005];
Order orderBook[10005];
int id = 1;

void trade(set<OrderEntry> &buy_orders, set<OrderEntry> &sell_orders, char type)
{
    while (!buy_orders.empty() && !sell_orders.empty())
    {
        auto buy_it = buy_orders.begin();
        auto sell_it = sell_orders.begin();

        if (buy_it->price < sell_it->price)
            break;

        Order &buy_order = orderBook[buy_it->order_id];
        Order &sell_order = orderBook[sell_it->order_id];
        int deal_quantity = min(buy_order.quantity, sell_order.quantity);
        double deal_price = (buy_order.price + sell_order.price) / 2.0;
        printf("deal--price:%6.1lf  quantity:%4d  ", deal_price, deal_quantity);
        if (type == 'b')
            printf("buyorder:%04d  sellorder:%04d\n", buy_order.order_id, sell_order.order_id);
        else
            printf("sellorder:%04d  buyorder:%04d\n", sell_order.order_id, buy_order.order_id);

        buy_order.quantity -= deal_quantity;
        sell_order.quantity -= deal_quantity;
        if (buy_order.quantity == 0)
            buy_orders.erase(buy_it);
        if (sell_order.quantity == 0)
            sell_orders.erase(sell_it);
    }
}

void inquire(const set<OrderEntry> &buy_orders, const set<OrderEntry> &sell_orders)
{
    cout << "buy orders:" << endl;
    for (const auto &entry : buy_orders)
    {
        Order order = orderBook[entry.order_id];
        if (order.quantity == 0)
            continue;
        order.show();
    }

    cout << "sell orders:" << endl;
    for (const auto &entry : sell_orders)
    {
        Order order = orderBook[entry.order_id];
        if (order.quantity == 0)
            continue;
        order.show();
    }
}

void repeal(const int &order_id)
{
    if (order_id < 1 || order_id > id){
        cout << "not found" << endl;
        return;
    }
    Order order = orderBook[order_id];
    if (!order.order_id){
        cout << "not found" << endl;
        return;
    }
    int code = order.code;
    char type = order.type;
    auto &orders = type == 'b' ? buy_orders[code] : sell_orders[code];
    OrderEntry order_entry = (OrderEntry){order_id, order.price, type};
    if (orders.find(order_entry) == orders.end())
        cout << "not found" << endl;
    else
    {
        orders.erase(orders.find(order_entry));
        cout << "deleted order:";
        order.show();
    }
}
int main()
{

    // freopen("input/ZY4-5.txt");

    while (true)
    {
        int action;
        cin >> action;
        if (action == 1)
        {
            double price;
            char type;
            int code, quantity;
            cin >> code >> price >> quantity >> type;
            printf("orderid: %04d\n", id);
            orderBook[id] = (Order(id, code, price, quantity, type));
            if (type == 'b')
                buy_orders[code].insert({id, price, type});
            else if (quantity > 0)
                sell_orders[code].insert({id, price, type});
            trade(buy_orders[code], sell_orders[code], type);
            id++;
        }
        else if (action == 2)
        {
            int query_code;
            scanf("%d", &query_code);
            inquire(buy_orders[query_code], sell_orders[query_code]);
        }
        else if (action == 3)
        {
            int query_order_id;
            scanf("%d", &query_order_id);
            repeal(query_order_id);
        }
        else if (action == 0)
            break;
    }

    freopen("CON","r",stdin);
    system("pause");

}