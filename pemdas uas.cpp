#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Appointment {
    string patientName;
    string appointmentDate;
    string appointmentTime;
};

class AppointmentSystem {
private:
    vector<Appointment> appointments;

public:
    void addAppointment() {
        Appointment newAppointment;
        cout << "Masukkan nama pasien: ";
        cin.ignore(); // Mengabaikan newline dari input sebelumnya
        getline(cin, newAppointment.patientName);
        cout << "Masukkan tanggal janji temu (DD/MM/YYYY): ";
        getline(cin, newAppointment.appointmentDate);
        cout << "Masukkan waktu janji temu (HH:MM): ";
        getline(cin, newAppointment.appointmentTime);

        appointments.push_back(newAppointment);
        cout << "Janji temu berhasil ditambahkan!\n";
    }

    void displayAppointments() {
        if (appointments.empty()) {
            cout << "Tidak ada janji temu yang terdaftar.\n";
            return;
        }

        cout << "\nDaftar Janji Temu:\n";
        for (const auto& appointment : appointments) {
            cout << "Nama Pasien: " << appointment.patientName << "\n";
            cout << "Tanggal: " << appointment.appointmentDate << "\n";
            cout << "Waktu: " << appointment.appointmentTime << "\n";
            cout << "-------------------------\n";
        }
    }
};

int main() {
    AppointmentSystem system;
    int choice;

    do {
        cout << "\nSistem Pendaftaran Janji Temu Pasien\n";
        cout << "1. Tambah Janji Temu\n";
        cout << "2. Tampilkan Janji Temu\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addAppointment();
                break;
            case 2:
                system.displayAppointments();
                break;
            case 3:
                cout << "Terima kasih! Sampai jumpa.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 3);

    return 0;
}