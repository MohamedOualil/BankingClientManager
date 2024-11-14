#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsUsers.h"

using namespace std;

class clsShowAddNewUser:protected clsScreen
{
    static const short Encryptionkey = 2;

    static int _ReadPermissionsToSet() {
        char Answer = 'n';
        cout << "\nDo You Want to Give Full acess? y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            return clsUsers::enPermissions::pAll;
        }
        int bPermissions = 0;

        cout << "\nDo You want give access to : \n";

        cout << "\nShow Client List? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            bPermissions += clsUsers::enPermissions::pClientList;
        }


        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            bPermissions += clsUsers::enPermissions::pAddClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            bPermissions += clsUsers::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            bPermissions += clsUsers::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            bPermissions += clsUsers::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            bPermissions += clsUsers::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            bPermissions += clsUsers::enPermissions::pManageUser;
        }

        cout << "\neLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            bPermissions += clsUsers::enPermissions::pLoginRegister;
        }

        return bPermissions;
    }

    static void _ReadUserInfo(clsUsers& User) {

        User.FirstName = clsInputValidate::ReadString("Enter Your First Name? ");
        User.LastName = clsInputValidate::ReadString("Enter Your Last Name? ");
        User.Email = clsInputValidate::ReadString("Enter Your Email? ");
        User.Phone = clsInputValidate::ReadString("Enter Your Phone? ");
        User.Password = clsInputValidate::ReadString("Enter Your Password? ");
        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUsers User) {

        cout << "\nUser Card: ";
        cout << "\n_______________________\n";
        cout << "\nFirst Name : " << User.FirstName;
        cout << "\nLast Name : " << User.LastName;
        cout << "\nFull Name : " << User.FullName();
        cout << "\nEmail : " << User.Email;
        cout << "\nPhone : " << User.Phone;
        cout << "\nUserName : " << User.UserName;
        cout << "\nPassword : " << User.Password;
        cout << "\nPermission : " << User.Permissions;
        cout << "\n_______________________\n";
    }


public:

    static void AddNewUser() {

        string Title = "\tAdd New Screen";
        _DrawScreenHeader(Title);

        string UserName;
        UserName = clsInputValidate::ReadString("Please Enter Your UserName? ");

        while (clsUsers::IsUserObjectExist(UserName)) {

            cout << "Error This UserName " << UserName << " Not Already Exist,\n";
            getline(cin >> ws, UserName);
        }
        clsUsers NewUser = clsUsers::GetAddNewUserObject(UserName);
        _ReadUserInfo(NewUser);

        clsUsers::enSaveResult SaveResult;
        SaveResult = NewUser.Save();
        switch (SaveResult)
        {
        case clsUsers::enSaveResult::svFailObjectEmpty:
            cout << "\n\nError account was not saved because it's Empty\n";
            break;
        case clsUsers::enSaveResult::svSuccessed:
            cout << "\nUser Added Successefuly:-( \n";
            _PrintUser(NewUser);
            break;
        case clsUsers::enSaveResult::svErorrUserNameExist:
            cout << "\nError account was not saved because UserName is used!\n";
            break;

        }



    }



};

