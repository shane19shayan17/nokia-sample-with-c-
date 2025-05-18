#include <iostream>
#include <time.h> //for srand
#include <map>
#include <algorithm>
#include <cmath> // for math function
#include <string>
#include <fstream>   // for files
#include <iomanip>   //for digits of float number
#include <sstream>   //for convert string to number
#include <windows.h> //for sleep

using namespace std;

// تعریف هدر تابع ها
void tab_maker();
void enter_password();
void getpassword(string &password);
void setting();
void guess();
void menu();
void back(int menu_item);
void calculator();
void add_contact();
void fill_map(map<string, string> &contact_map);
void show_contact();
void delete_contact();
void off();
void contact_menu();
void search();
void turn_off(string input);
bool is_availabe(string search_name, string contact);

// برای ساخت تب
void tab_maker()
{
    cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t';
}

// خاموش کردن
void turn_off(string input)
{
    if (input == "off")
    {
        off();
    }
    else if (input == "menu")
    {
        menu();
    }
}

// منو
void menu()
{
    tab_maker();
    cout << "1-CALCULATOR" << endl;
    tab_maker();
    cout << "2-GUESSNUMBER" << endl;
    tab_maker();
    cout << "3-CONTACTS" << endl;
    tab_maker();
    cout << "4-SETTING" << endl;
    tab_maker();
    cout << "5-OFF" << endl;
    int menu_number;
    while (true)
    {
        string menu_string;
        cin >> menu_string;
        turn_off(menu_string);
        stringstream ss(menu_string);       // برای تبدیل استرینگ به عدد
        if (ss >> menu_number and ss.eof()) // چک کردن تبدیل به عدد
        {
            break;
        }
        else
        {
            cout << "ERROR !" << endl;
        }
    }
    if (menu_number == 1)
    {
        cout << endl;
        tab_maker();
        cout << "CALCULATOR" << endl;
        cout << endl;
        calculator();
    }
    else if (menu_number == 2)
    {
        cout << endl;
        tab_maker();
        cout << "GUESS NUMBER GAME" << endl;
        cout << endl;
        guess();
    }
    else if (menu_number == 3)
    {
        cout << endl;
        tab_maker();
        cout << "CONTACTS" << endl;
        cout << endl;
        contact_menu();
    }
    else if (menu_number == 4)
    {
        cout << endl;
        tab_maker();
        cout << "SETTING" << endl;
        cout << endl;
        setting();
    }
    else if (menu_number == 5)
    {
        off();
    }
    else
    {
        cout << "please choose a correct menu item !" << endl;
        menu();
    }
}

// برای برگشت به منو
void back(int menu_item)
{
    cout << "what do you want to do (again or menu or off)? ";
    string doing;
    cin >> doing;
    if (doing == "again")
    {
        if (menu_item == 1)
        {
            calculator();
        }
        else if (menu_item == 2)
        {
            guess();
        }
        else if (menu_item == 3)
        {
            contact_menu();
        }
        else if (menu_item == 4)
        {
            setting();
        }
    }
    else if (doing == "menu")
    {
        menu();
    }
    else if (doing == "off")
    {
        off();
    }
    else
    {
        cout << "wrong" << endl;
        back(menu_item);
    }
}

// برای خاموش کردن
void off()
{
    cout << "goodbye" << endl;
    exit(0); // برای بستن برنامه
}

// بازی حدس عدد
void guess()
{
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess;
    int false_number = 0, situation, alternative;
    while (false_number < 5) // برای 5 بار تعداد خطا
    {
        while (true)
        {
            string string_guess;
            cout << "guess number: ";
            cin >> string_guess;
            turn_off(string_guess);
            // برای بین 1 تا 100 بودن عدد
            if (string_guess.length() > 2 and string_guess != "100")
            {
                cout << "you can chose number between 1 to 100;" << endl;
                continue;
            }
            // تبدیل رشته به عدد
            stringstream ss(string_guess);
            if (ss >> guess and ss.eof())
            {
                break;
            }
            else
            {
                cout << "you can chose number between 1 to 100;" << endl;
            }
        }
        // برای هوشمند سازی بازی
        if (situation == 1)
        {
            if (guess <= alternative)
            {
                cout << "enter LARGER number !!!" << endl;
                continue;
            }
        }
        else if (situation == 3)
        {
            if (guess >= alternative)
            {
                cout << "enter SMALLER number !!!" << endl;
                continue;
            }
        }
        else
        {
            situation = 2;
        }
        // شروع بازی
        if (guess == number)
        {
            cout << "your guess is true.\nyou win" << endl;
            break;
        }
        else if (guess < number)
        {
            situation = 1;
            cout << "guess is smaller." << endl;
            ++false_number;
            cout << "you have " << 5 - false_number << " try left" << endl;
        }
        else if (guess > number)
        {
            situation = 3;
            cout << "guess is bigger." << endl;
            ++false_number;
            cout << "you have " << 5 - false_number << " try left" << endl;
        }
        if (false_number == 5)
        {
            cout << "GAME OVER" << endl;
            cout << "number is: " << number << endl;
        }
        alternative = guess; // جایگزین برای هوشمند سازی
    }
    back(2);
}

// تابع برای رمز ورود
void enter_password()
{
    string password;
    getpassword(password);
    int false_password = 0; // برای تعداد خطا
    string input;           // رمز ورودی
    bool is_true;           // چک کردن رمز
    cout << endl;
    tab_maker();
    cout << "welcom to NOKIASIM" << endl;
    cout << endl;
    cout << "enter password: ";
    while (true)
    {
        cin >> input;
        is_true = input == password;
        if (is_true)
        {
            break;
        }
        else
        {
            ++false_password;
            if (false_password == 3)
            {
                cout << "3 failed try" << endl;
                for (int i = 10; i > 0; i--)
                {
                    cout << "you lock for " << i << " second !" << endl;
                    cout.flush();
                    Sleep(1000);
                    system("cls");
                }
                enter_password();
            }
            else
            {
                system("cls");
                cout << input << " was wrong !" << endl;
                cout << "try again(" << 3 - false_password << " try left) : ";
            }
            continue;
        }
    }
    tab_maker();
    cout << "WELCOM" << endl;
    cout << endl;
    menu();
}

// تنظیمات
void setting()
{
    tab_maker();
    cout << "1-CHANGE PASSWORD" << endl;
    tab_maker();
    cout << "2-BACK" << endl;
    int setting_menu;
    string string_item;
    while (true)
    {
        while (true) // برای دریافت استرینگ و تبدیل به عدد
        {
            cin >> string_item;
            turn_off(string_item);
            stringstream ss(string_item);
            if (ss >> setting_menu and ss.eof())
            {
                break;
            }
            else
            {
                cout << "ERROR" << endl;
            }
        }
        if (setting_menu == 1)
        {
            while (true) // تایید پسورد اولیه
            {
                string input;
                string password;
                getpassword(password);
                cout << "enter current password: ";
                cin >> input;
                turn_off(input);
                bool is_true = (password == input);
                if (is_true == 1)
                {
                    while (true) // برای اینکه اگر تایید اشتباه بود
                    {
                        cout << "enter new password: ";
                        string new_password1;
                        cin >> new_password1;
                        turn_off(new_password1);
                        int z = 0;
                        for (int i = 0; i < 4; i++) // چک کردن فقط عدد بودن و 4 رقمی بودن پسوورد
                        {
                            if (((char)new_password1[i] < 48 or (char) new_password1[i] > 57) and new_password1.length() != 4)
                            {
                                z = 1;
                                cout << "ERROR" << endl;
                                break;
                            }
                        }
                        if (z == 1) // اگر فقط عدد نبود تکرار فرایند
                        {
                            continue;
                        }
                        cout << "confirm new password: "; // تایید پسوورد جدید
                        string new_password2;
                        cin >> new_password2;
                        turn_off(new_password2);
                        int j = 0;
                        for (int i = 0; i < 4; i++) // چک کردن فقط عدد بودن و 4 رقمی بودن پسوورد
                        {
                            if (((char)new_password2[i] < 48 or (char) new_password2[i] > 57) and new_password2.length() != 4)
                            {
                                j = 1;
                                cout << "ERROR" << endl;
                                break;
                            }
                        }
                        if (j == 1) // اگر فقط عدد نبود تکرار فرایند
                        {
                            continue;
                        }
                        if (new_password1 == new_password2)
                        {
                            ofstream write("password.txt"); // برای سیو پسورد
                            // password = new_password1;
                            write << new_password1 << endl;
                            write.close();
                            cout << "password changing is successful." << endl;
                            break; // وقتی تایید  پسوورد درست بود
                        }
                        else
                        {
                            cout << "password connfirmation is wrong." << endl;
                        }
                    }
                    break; // خروج ار چرخه تایید پسوورد اول
                }
                else
                {
                    cout << "current password is wrong." << endl;
                }
            }
            break;
        }
        else if (setting_menu == 2)
        {
            back(4);
            break;
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }
    enter_password();
}

// ماشین حساب
void calculator()
{
    double a, b, pi = M_PI;
    string stringinput1, stringinput2;
    while (true)
    {
        cout << "enter first number: ";
        cin >> stringinput1;
        turn_off(stringinput1);
        if (stringinput1.length() > 8) // کنترل ورودی به 8 رقم
        {
            cout << "ERROR !" << endl;
        }
        stringstream ss(stringinput1); // برای تبدیل استرینگ به عدد
        if (ss >> a and ss.eof())      // چک کردن تبدیل به عدد
        {
            break;
        }
        else
        {
            cout << "ERROR !" << endl;
        }
    }
    cout << "enter operator(+ - / * pow radical log sin cos): ";
    string opr;
    while (true) // برای خطا در اوپراتور
    {
        cin >> opr;
        turn_off(opr);
        if (opr == "+")
        {
            while (true) // برای اینکه فقط عدد دریافت کنیم
            {
                cout << "enter second number: ";
                cin >> stringinput2;
                turn_off(stringinput2);
                if (stringinput1.length() > 8) // کنترل تعداد ارقام ورودی
                {
                    cout << "ERROR !" << endl;
                }
                stringstream ss(stringinput2);
                if (ss >> b and ss.eof())
                {
                    break;
                }
                else
                {
                    cout << "ERROR" << endl;
                    ;
                }
            }
            cout << "result: " << fixed << setprecision(8) << a + b << endl;
            break;
        }
        else if (opr == "-")
        {
            while (true)
            {
                cout << "enter second number: ";
                cin >> stringinput2;
                turn_off(stringinput2);
                if (stringinput1.length() > 8) // کنترل ورودی به 8 رقم
                {
                    cout << "ERROR !" << endl;
                }
                stringstream ss(stringinput2);
                if (ss >> b and ss.eof())
                {
                    break;
                }
                else
                {
                    cout << "ERROR" << endl;
                    ;
                }
            }
            cout << "result: " << fixed << setprecision(8) << a - b << endl;
            break;
        }
        else if (opr == "/")
        {
            while (true)
            {
                cout << "enter second number: ";
                cin >> stringinput2;
                turn_off(stringinput2);
                if (stringinput1.length() > 8) // کنترل ورودی به 8 رقم
                {
                    cout << "ERROR !" << endl;
                }
                stringstream ss(stringinput2);
                if (ss >> b and ss.eof())
                {
                    break;
                }
                else
                {
                    cout << "ERROR" << endl;
                    ;
                }
            }
            cout << "result: " << fixed << setprecision(8) << a / b << endl;
            break;
        }
        else if (opr == "*")
        {
            while (true)
            {
                cout << "enter second number: ";
                cin >> stringinput2;
                turn_off(stringinput2);
                if (stringinput1.length() > 8) // کنترل ورودی به 8 رقم
                {
                    cout << "ERROR !" << endl;
                }
                stringstream ss(stringinput2);
                if (ss >> b and ss.eof())
                {
                    break;
                }
                else
                {
                    cout << "ERROR" << endl;
                    ;
                }
            }
            cout << "result: " << fixed << setprecision(8) << a * b << endl;
            break;
        }
        else if (opr == "pow")
        {
            while (true)
            {
                cout << "enter second number: ";
                cin >> stringinput2;
                turn_off(stringinput2);
                if (stringinput1.length() > 8) // کنترل ورودی به 8 رقم
                {
                    cout << "ERROR !" << endl;
                }
                stringstream ss(stringinput2);
                if (ss >> b and ss.eof())
                {
                    break;
                }
                else
                {
                    cout << "ERROR" << endl;
                    ;
                }
            }
            cout << "result: " << fixed << setprecision(8) << pow(a, b) << endl;
            break;
        }
        else if (opr == "radical")
        {
            cout << "result: " << fixed << setprecision(8) << pow(a, 0.5) << endl;
            break;
        }
        else if (opr == "log")
        {
            cout << "result :" << fixed << setprecision(8) << log10(a) << endl;
            break;
        }
        else if (opr == "sin")
        {
            double pi = M_PI;
            double radian = ((a * pi) / 180);
            cout << "result: " << fixed << setprecision(8) << sin(radian) << endl;
            break;
        }
        else if (opr == "cos")
        {
            float pi = M_PI;
            float radian = ((a * pi) / 180);
            cout << "result: " << fixed << setprecision(8) << cos(radian) << endl;
            break;
        }
        else
        {
            cout << "ERROR\nenter operator(+ - / * pow radical log sin cos): " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    back(1);
}

// برای مخاطبین
void contact_menu()
{
    tab_maker();
    cout << "1-SHOW CONTACTS LIST" << endl;
    tab_maker();
    cout << "2-ADD NEW CONTACT" << endl;
    tab_maker();
    cout << "3-SEARCH" << endl;
    tab_maker();
    cout << "4-delete" << endl;
    tab_maker();
    cout << "5-BACK" << endl;
    int contact_menu_number; // برای انتخاب منو
    while (true)
    {
        string contac_menu_string;
        cin >> contac_menu_string;
        turn_off(contac_menu_string);
        stringstream ss(contac_menu_string);
        if (ss >> contact_menu_number and ss.eof())
        {
            break;
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }
    if (contact_menu_number == 1)
    {
        show_contact(); // برای نمایش مخاطبین
    }
    else if (contact_menu_number == 2)
    {
        add_contact(); // برای اصافه کردن مخاطب جدید
    }
    else if (contact_menu_number == 3)
    {
        search(); // برای سرچ در مخاطبین
    }
    else if (contact_menu_number == 4)
    {
        delete_contact(); // برای حذف مخاطب
    }
    else if (contact_menu_number == 5)
    {
        back(3);
    }
    else
    {
        cout << "please select correct item !" << endl;
        contact_menu();
    }
}

// برای ساخت مپ مخاطبین
void fill_map(map<string, string> &contact_map)
{
    ifstream read;
    int k = 0;
    read.open("contact_list.txt"); // باز کردن فایل مخاطبین
    string line, key, value;
    while (getline(read, line)) // خواندن فایل و پر کردن مپ
    {
        if (line != "------------" and k == 0)
        {
            key = line;
            k = 1;
            continue;
        }
        if (k == 1)
        {
            value = line;
            k = 0;
            continue;
        }
        contact_map[key] = value;
    }
}

// برای اضافه کردن مخاطبین
void add_contact()
{
    ofstream contact_file("contact_list.txt", ios::app);
    string contact_name;   // نام مخاطب جدید
    string contact_number; // شماره مخاطب جدید
    cout << "what's the name of contact? ";
    cin >> contact_name;
    turn_off(contact_name);
    cout << "what's the number of contact? ";
    cin >> contact_number;
    turn_off(contact_number);
    string cont = contact_name + '\n' + contact_number + "\n------------";
    contact_file << cont << endl; // اضافه کردن مخاطب به فایل
    cout << "adding contact is successful." << endl;
    contact_menu();
}

// show contact
void show_contact()
{
    string show; // استرینگ برای خواندن فایل
    ifstream read_file;
    read_file.open("contact_list.txt"); // باز کردن فایل مخاطبین
    tab_maker();
    cout << "CONTACTS LIST" << endl;
    cout << endl;
    while (getline(read_file, show)) // خواندن  فایل و نمایش مخاطبین
    {
        cout << show << endl;
    }
    read_file.close(); // بستن فایل
    contact_menu();    // برگشت به منو مخاطبین
}

// برای حذف مخاطبین
void delete_contact()
{
    map<string, string> contact; // مپ برای راحتی کار با فایل
    fill_map(contact);           // تابع پر کردن مپ با اطلاعات داخل فایل
    string show;                 // استرینگ برای خواندن فایل
    ifstream read_file;
    read_file.open("contact_list.txt"); 
    tab_maker();
    cout << "CONTACTS LIST" << endl;
    cout << endl;
    while (getline(read_file, show)) 
    {
        cout << show << endl;
    }
    read_file.close(); // بستن فایل
    cout << "enter name or number that you want to delete: ";
    string search;
    cin >> search;
    turn_off(search);
    int k = 0;
    for (auto i : contact)
    {
        if (i.first == search or i.second == search) // برای گشتن در مپ
        {
            contact.erase(i.first); // برای خذف مخاطب سرچ شده
            cout << "delete contact is successful." << endl;
            k = 0;
            break;
        }
        else
        {
            k = 1; // اگر مخاطب وجود نداشت
        }
    }
    if (k == 1)
    {
        cout << "there is no contact with following id." << endl;
    }
    ofstream newfile("contact_list.txt"); // بار کردن فایل برای بازنویسی فایل
    for (auto i : contact)
    {
        newfile << i.first << endl
                << i.second << endl
                << "------------" << endl;
    }
    newfile.close(); // بستن فایل
    contact_menu();
}

// تشخیص وجود کلمه سرچ شده در مخاطبین
bool is_availabe(string search_name, string contact)
{
    int j = 0, s = search_name.length();
    for (char i : contact)
    {
        if (j < s and (tolower(i) == tolower(search_name[j])))
        {
            ++j;
        }
    }
    return j == s;
}

// برای سرچ مخاطبین
void search()
{
    map<string, string> contact_map;
    fill_map(contact_map); // پر کردن مپ
    string main_search, final_search;
    while (true)
    {
        cout << "enter name you want to search or 'stop' to stop searching: " << endl;
        string search_input;
        cin >> search_input;
        turn_off(search_input);
        if (search_input == "stop") // استپ سرچ
        {
            break;
        }
        final_search = main_search + search_input;
        for (auto i : contact_map)
        {
            if (is_availabe(final_search, i.first) or is_availabe(final_search, i.second)) // تشخیص وجود سرپ در مخاطبین
            {
                main_search = final_search;
            }
        }
        cout << "result for: '" << final_search << "'" << endl;
        cout << endl;
        int k = 0;
        for (auto i : contact_map) // نمایش نتایج
        {
            if (is_availabe(final_search, i.first) or is_availabe(final_search, i.second))
            {
                cout << i.first << endl;
                cout << i.second << endl;
                cout << "------------" << endl;
                cout << endl;
                k = 1;
            }
        }
        if (k == 0)
        {
            cout << "there is no contact with this id !" << endl;
        }
    }
    contact_menu();
}

// برای تشخیص پسورد
void getpassword(string &password)
{
    ifstream read_password;
    read_password.open("password.txt");
    string line;
    while (getline(read_password, line))
    {
        password = line;
    }
    read_password.close();
}

// تابع اصلی
int main()
{
    enter_password(); // تایع ورود به برنامه
    return 0;
}