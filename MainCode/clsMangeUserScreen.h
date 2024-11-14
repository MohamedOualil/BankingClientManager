#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsShowListUsers.h"
#include "clsShowAddNewUser.h"
#include "clsShowDeleteUsersScreen.h"
#include "clsShowUpdateUserScreen.h"
#include "clsShowFindUserScreen.h"

using namespace std;

class clsMangeUserScreen:protected clsScreen
{
    enum enUsersMenue {
        eShowUsers = 1,
        eAddUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eOptionMainMenue = 6
    };

    static void _GoBackToUserMainMenue() {
        cout << "\nPress any key to go back to Main Menue...";
        system("pause>0");
        ShowUsersMenueScreen();
    }

    static short _ReadUserMenueOption() {
        short choice=0;
        cout << "\nChoose what do you want to do? [1 to 6]? ";
        choice = clsInputValidate::ReadShortNumberBetween(1, 6);
        return choice;
    }

    static void _ShowAllUserScreen() {
        clsShowListUsers::ShowUserList();
    }

    static void _ShowAddNewUserScreen() {
        clsShowAddNewUser::AddNewUser();
    }

    static void _ShowDeleteUserScreen() {
        clsShowDeleteUsersScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen() {
        clsShowUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen() {
        clsShowFindUserScreen::ShowFindUserScreen();
    }


    static void _PerformUsersMenueOption(enUsersMenue UsersMenue) {
        switch (UsersMenue)
        {
        case enUsersMenue::eShowUsers:
            system("cls");
            _ShowAllUserScreen();
            _GoBackToUserMainMenue();
            break;
        case enUsersMenue::eAddUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToUserMainMenue();
            break;
        case enUsersMenue::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToUserMainMenue();
            break;
        case enUsersMenue::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToUserMainMenue();
            break;
        case enUsersMenue::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToUserMainMenue();
            break;
        case enUsersMenue::eOptionMainMenue:
            break;
        }
    }

public:

    static void ShowUsersMenueScreen() {
        if (!CheckAccessRights(clsUsers::enPermissions::pManageUser)) {
            return;
        }
        system("cls");
        _DrawScreenHeader("\tMange Users Screen");
        
        cout << setw(37) << left << "" << "=====================================================\n";
        cout <<setw(37)  << left << "" << "\t\tMange Users Menue \n";
        cout <<setw(37)  << left << "" << "=====================================================\n";
        cout <<setw(37)  << left << "" << "[1] List Users. \n";
        cout <<setw(37)  << left << "" << "[2] Add New User. \n";
        cout <<setw(37)  << left << "" << "[3] Delete User. \n";
        cout <<setw(37)  << left << "" << "[4] Update User. \n";
        cout <<setw(37)  << left << "" << "[5] Find User. \n";
        cout <<setw(37)  << left << "" << "[6] Main Menue. \n";
        cout <<setw(37)  << left << "" << "=====================================================\n";
        short Option = _ReadUserMenueOption();
        _PerformUsersMenueOption((enUsersMenue)Option);
    }





};

