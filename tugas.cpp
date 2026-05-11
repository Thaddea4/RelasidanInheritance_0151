#include <iostream>
#include <string>

using namespace std;

class user {
public:
    static int globalId;

    int id;
    string nama;
    string email;

    int generateId() {
        return ++globalId;
    }

    user(string pNama, string pEmail)
        : nama(pNama), email(pEmail)
    {
        id = generateId();
    }
};

int user::globalId = 0;


class member : public user {
public:
    bool status;

    member(string pNama, string pEmail)
        : user(pNama, pEmail)
    {
        status = true;
    }

   void showProfile() {
    cout << "ID : " << id << endl;
    cout << "Nama : " << nama << endl;
    cout << "Email : " << email << endl;

    if(status)
        cout << "Status : Aktif" << endl;
    else
        cout << "Status : Tidak Aktif" << endl;

    cout << endl;
}
};


class admin : public user {
public:
    admin(string pNama, string pEmail)
        : user(pNama, pEmail)
    {
    }

    void showAllMember(member *m1, member *m2) {
        m1->showProfile();
        m2->showProfile();
    }

    void toggleActivationMember(member *pMember) {
        pMember->status = !pMember->status;
    }
};


int main() {

    admin* admin1 = new admin("Budi", "admin@gmail.com");

    member* member1 = new member("Thaddea", "thaddeasy@gmail.com");
    member* member2 = new member("Jaehyun", "jjaehyun@gmail.com");

    admin1->showAllMember(member1, member2);

    delete admin1;
    delete member1;
    delete member2;

    return 0;
}