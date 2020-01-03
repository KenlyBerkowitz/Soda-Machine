#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct DrinkInfo
{
  string drinkName;
  double drinkCost;
  int drinkQty;
};

void initDataDrinks(DrinkInfo[]);  //initialize all drink data (comment 1)
void displayMenu(DrinkInfo[]);  //displays the menu to the screen (comment 2)
void outOfOrderCost(DrinkInfo[], int);  //determine whether to ouput the price in the menu or if it is out of order (comment 3)
void getSwitchChoice(int &);  // get users choice of soda (comment 4)
void getInsertMoney(double &);  //put money in machine (comment 5)
void calcReturn(double &, int, DrinkInfo[], double &, double &);  //calculate the amount to be returned (comment 6)
void performTransaction(int, double &, double &, DrinkInfo[], double &);  //decrement the qty (comment 7)

int main()
{
  double moneyMade = 0.0;  //will add the total cost of drinks sold (comment 8)
  const int SIZE = 5;
  DrinkInfo drinks[SIZE];  //hold the drink objects in an array based structure in order to change them out easily and send through functions effectively (comment 9)
  int switchChoice;  //user input number that will be used as switch case number (comment 10)
  double insertedMoney;  //holds the money ibserted into the machine (comment 11)
  double change;  //the money to be returned to the customer (comment 12)

  cout << setprecision(2) << fixed;

  initDataDrinks(drinks);
  displayMenu(drinks);

  do
  {
    getSwitchChoice(switchChoice);
    switch(switchChoice)
    {
      case 1 : if(drinks[switchChoice - 1].drinkQty > 0)  //will check whether the drink choice has drinks and if not, it will display out of order (comment 13)
               {
                 performTransaction(0, change, insertedMoney, drinks, moneyMade);
                 system("clear");
                 displayMenu(drinks);
               }
               else
                 cout << "Out of Order";
               break;
      case 2 : if(drinks[switchChoice - 1].drinkQty > 0)
               {
                 performTransaction(1, change, insertedMoney, drinks, moneyMade);
                 system("clear");
                 displayMenu(drinks);
               }
               else
                 cout << "Out of Order";
               break;
      case 3 : if(drinks[switchChoice - 1].drinkQty > 0)
               {
                 performTransaction(2, change, insertedMoney, drinks, moneyMade);
                 system("clear");
                 displayMenu(drinks);
               }
               else
                 cout << "Out of Order";
               break;
      case 4 : if(drinks[switchChoice - 1].drinkQty > 0)
               {
                 performTransaction(3, change, insertedMoney, drinks, moneyMade);
                 system("clear");
                 displayMenu(drinks);
               }
               else
                 cout << "Out of Order";
               break;
      case 5 : if(drinks[switchChoice - 1].drinkQty > 0)
               {
                 performTransaction(4, change, insertedMoney, drinks, moneyMade);
                 system("clear");
                 displayMenu(drinks);
               }
               else
                 cout << "Out of Order";
               break;
      default: cout << "Thank you for your purchase. ";
    }
  }while(switchChoice != 6);

  cout << endl << "Total Earnings: $" << moneyMade << endl;

  return 0;
}

void initDataDrinks(DrinkInfo initDrinkArr[])  //initialize the drinks in an array so you can switch out the drinks easily (comment 14)
{
  initDrinkArr[0].drinkName = "Cola";
  initDrinkArr[0].drinkCost = 0.75;
  initDrinkArr[0].drinkQty = 20;

  initDrinkArr[1].drinkName = "Root Beer";
  initDrinkArr[1].drinkCost = 0.75;
  initDrinkArr[1].drinkQty = 20;

  initDrinkArr[2].drinkName = "Lemon-Lime";
  initDrinkArr[2].drinkCost = 0.75;
  initDrinkArr[2].drinkQty = 20;

  initDrinkArr[3].drinkName = "Grape Soda";
  initDrinkArr[3].drinkCost = 0.80;
  initDrinkArr[3].drinkQty = 20;

  initDrinkArr[4].drinkName = "Cream Soda";
  initDrinkArr[4].drinkCost = 0.80;
  initDrinkArr[4].drinkQty = 20;
}

void displayMenu(DrinkInfo dispDrinkArr[])
{
  cout << setw(5) << "*****************************************\n"
       << setw(5) << "************    DRINK UP   **************\n"
       << left << setw(18) << "Drinks" << setw(15) << "Cost" << endl
       << left << setw(18) << "-------" << setw(15) << "-------";
  cout << endl << left << "1. " << setw(15) << dispDrinkArr[0].drinkName;
  outOfOrderCost(dispDrinkArr, 0);
  cout << endl << left << "2. " << setw(15) << dispDrinkArr[1].drinkName;
  outOfOrderCost(dispDrinkArr, 1);
  cout << endl << left << "3. " << setw(15) << dispDrinkArr[2].drinkName;
  outOfOrderCost(dispDrinkArr, 2);
  cout << endl << left << "4. " << setw(15) << dispDrinkArr[3].drinkName;
  outOfOrderCost(dispDrinkArr, 3);
  cout << endl << left << "5. " << setw(15) << dispDrinkArr[4].drinkName;
  outOfOrderCost(dispDrinkArr, 4);
  cout << endl << endl << left << "6. Leave the drink machine." << endl;
}

void outOfOrderCost(DrinkInfo oooDrinkArr[], int drinkNum)
{
  if(oooDrinkArr[drinkNum].drinkQty == 0)
    cout << "Out Of Order ";
  else
    cout << oooDrinkArr[drinkNum].drinkCost;
}

void getSwitchChoice(int &getChoice)
{
  cout << "\nChoose option: ";
  do
  {
    cin >> getChoice;
    cin.ignore(1000, 10);
    if(getChoice <= 0 || getChoice > 6)
      cout << endl << "Invalid option" << endl << "Choose option: ";
  }while(getChoice <= 0 || getChoice > 6);
}

void performTransaction(int costNum, double &coins, double &insertCash, DrinkInfo drinkArray[], double &moneyEarned)
{
  double moneyDue = drinkArray[costNum].drinkCost;

  cout << "\nEnter an amount of money greater than zero and less than or equal to 1 dollar. " << endl;
  do
  {
    getInsertMoney(insertCash);
    calcReturn(coins, costNum, drinkArray, insertCash, moneyDue);
  }while(moneyDue > 0);

  cout << "Enjoy your beverage. " << endl;

  drinkArray[costNum].drinkQty -= 1;  //decrements the quantity by one (comment 1)
  cout << "There are " << drinkArray[costNum].drinkQty << " drinks of that type left.";

  moneyEarned = moneyEarned + drinkArray[costNum].drinkCost;  //adds the cost of the drink sold to money earned (comment 15)

  cout << "\n\nPress any key to return to menu." << endl;
  cin.get();
}

void getInsertMoney(double &cash)
{
  do
  {
    cout << "Insert cash: ";
    cin >> cash;
    cin.ignore(1000, 10);
    if(cash < 0)
      cout << "Money inserted must be above zero.\n";
    if(cash > 1)
      cout << "Money inserted must be less than or equal to a dollar.\n";
  }while(cash < 0 || cash > 1);
}

void calcReturn(double &coin, int arrNum, DrinkInfo drinkArr[], double &insertCash, double &due)
{
  static double cash = 0;
  cash+=insertCash;  //adds the inserted cash to cash (comment 16)
  due = drinkArr[arrNum].drinkCost - cash;


  if(due < 0)  //checks if the amount has been paid and outputs what the machine should return in change (comment 17)
  {
    cout << "Your change is " << (due / -1) << " cents. \nPlease take your change out of the dispenser. ";
    cash = 0.00;  //puts the static variable back to zero for next function use (comment 18)
    due = 0.00;
  }
  else if(due == 0)  //checks if they paid exact amount and resets cash variable (comment 19)
  {
    cash = 0.0;  //puts the static variable back to zero for next function use (comment 20)
    due = 0.0;
  }
  else
  {
    cout << "Please insert more cash." << endl;
  }
}
