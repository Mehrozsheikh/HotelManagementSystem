#include "Validator.h"

// Validtion Functions 
// Starts From here.

bool Validator::Names_Validator(string name)
{
    bool flag = true;

    for (int i = 0; i < name.length(); i++)
    {
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')))
            flag = false;
    }

    return flag;
}

bool Validator::CNIC_Validator(string CNIC)
{
    bool flag = false;
    int cinc_size;

    cinc_size = CNIC.length();

    if (cinc_size == 15)
    {
        if (CNIC[5] == '-' && CNIC[13] == '-')
        {
            for (int n = 0; n < 5; n++)
            {
                if (CNIC[n] >= '0' && CNIC[n] <= '9')
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                for (int n = 6; n < 13; n++)
                {
                    if (CNIC[n] >= '0' && CNIC[n] <= '9')
                    {
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag == true)
                {
                    if (CNIC[14] >= '0' && CNIC[14] <= '9')
                    {
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                    }
                }
            }
        }

    }
    return flag;
}

bool Validator::email_Validator(string e_mail)
{
    bool flag = false;
    int email_size;

    email_size = e_mail.length();

    if (e_mail[0] != '@' && e_mail[email_size - 4] == '.' && e_mail[email_size - 3] == 'c' && e_mail[email_size - 2] == 'o' && e_mail[email_size - 1] == 'm')
    {

        for (int i = 0; i < email_size; i++)
        {
            if (e_mail[i] == '@')
            {
                flag = true;

            }
        }
    }
    return flag;

}

bool Validator::Phone_Validator(string phone_number)
{
    bool flag = false;
    int size = phone_number.length();

    if (size == 12 && phone_number[4] == '-')
    {

        for (short i = 0; i < size; i++)
        {
            if ((phone_number[i] >= '0' && phone_number[i] <= '9') && phone_number[i] == '-')
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }

        }
    }
    else if (size == 11)
    {
        for (short i = 0; i < size; i++)
        {
            if ((phone_number[i] >= '0' && phone_number[i] <= '9'))
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }

        }
    }
    return flag;

}

bool Validator::arrival_Validator(string date_arrival)
{
    bool flag = false;
    short size = date_arrival.length();

    if (size == 10 && date_arrival[2] == '/' && date_arrival[5] == '/')
    {
        if ((date_arrival[0] >= '0' && date_arrival[0] <= '3') && (date_arrival[1] >= '0' && date_arrival[1] <= '9'))
        {
            flag = true;
        }
        else
        {
            flag = false;
        }

        if (flag == true)
        {
            if ((date_arrival[3] >= '0' && date_arrival[3] <= '9') && (date_arrival[4] >= '0' && date_arrival[4] <= '2'))
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
            if (flag == true)
            {
                for (short i = 6; i < size; i++)
                {
                    if ((date_arrival[i] >= '0' && date_arrival[i] <= '9'))
                    {
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }

                }

            }

        }

    }
    return flag;
}

bool Validator::username_valiadator(string enter_username)
{
    bool flag = true;

    int len = enter_username.length();
    for (short i = 0; i < len; i++)
    {
        if (enter_username[i] == ' ')
        {
            flag = false;
            break;
        }
    }

    return flag;
}

bool Validator::password_validator(string enter_password)
{
    bool flag = false;

    int len = enter_password.length();

    if (len >= 8)
    {
        for (short i = 0; i < len; i++)
        {
            if (enter_password[i] >= 'A' && enter_password[i] <= 'Z')
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            for (short j = 0; j < len; j++)
            {
                if ((enter_password[j] >= 33 && enter_password[j] <= 47) || (enter_password[j] >= 58 && enter_password[j] <= 64) || (enter_password[j] >= 91 && enter_password[j] <= 96) || (enter_password[j] >= 123 && enter_password[j] <= 126))
                {
                    flag = true;
                    break;
                }
                else
                {
                    flag = false;
                }
            }
        }
    }
    return flag;
}

bool Validator::integar_validator(string days)
{
    bool flag = false;
    short size = days.length();

    for (short i = 0; i < size; i++)
    {
        if (days[i] >= '0' && days[i] <= '9')
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }

    return flag;
}