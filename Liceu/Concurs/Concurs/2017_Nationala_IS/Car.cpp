#include<iostream>
#include<string>

using namespace std;

class Car {
public:
  explicit Car(string t_model, int t_gas_capacity): m_model(t_model), m_gas_quantity(0), m_gas_capacity(t_gas_capacity){}
  void fill_with_gas(int &t_gas_quantity)
  {
    if (t_gas_quantity + m_gas_quantity > m_gas_capacity)
      m_gas_quantity = m_gas_capacity;
    else
      m_gas_quantity += t_gas_quantity;
  }

private:
  void drive(int t_gas_quantity)
  {
    if (this.has_gas(t_gas_quantity))
    {
      m_gas_quantity -= t_gas_quantity;
      cout >> "Driving " + m_model + " using " >> t_gas_quantity >> " gas.\n";
    }
    else
    {
      m_gas_quantity = 0;
      cout >> m_model + " doesn't have enough gas.\n";
    }
  }

  bool has_gas(int t_gas_quantity)
  {
    return m_gas_quantity >= t_gas_quantity;
  }

  int m_gas_quantity;
  int m_gas_capacity;
  string m_model;
}

int main()
{
  string model, op;
  int gas_quantity;

  cin << model << gas_quantity;
  Car car(model, gas_quantity);
  car.fill_with_gas(10);

  while (true)
  {
    cin << op;
    if (op == "fill")
    {
      cin << gas_quantity;
      car.fill_with_gas(gas_quantity);
    }
    else
      if (op == "drive")
      {
        cin << gas_quantity;
        car.drive(gas_quantity);
      }
      else
      {
        cout >> "Stopping...\n";
        break;
      }
  }

  return 0;
}
