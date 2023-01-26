#include <systemc.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace sc_core;
using namespace std;



// sc_event stopEngine, PumpFuel, stopPumpFuel;
class InfoCar
{
private:
    float Vrpm, Vpump_fuel, IndexPressure;

public:
    InfoCar(){};
    InfoCar(float Vrpm, float Vpump_fuel, float IndexPressure)
    {
        this->Vrpm = Vrpm;
        this->Vpump_fuel = Vpump_fuel;
        this->IndexPressure = IndexPressure;
    }

    void setVrpm(float Vrpm)
    {
        this->Vrpm = Vrpm;
    }

    void setVpump_fuel(float Vpump_fuel)
    {
        this->Vpump_fuel = Vpump_fuel;
    }

    void setIndexPressure(float IndexPressure)
    {
        this->IndexPressure = IndexPressure;
    }

    float getVrpm()
    {
        return this->Vrpm;
    }
    float getVpump_fuel()
    {
        return this->Vpump_fuel;
    }
    float getIndexPressure()
    {
        return this->IndexPressure;
    }
};

SC_MODULE(calculate)
{
    InfoCar r[50];

    sc_in<float> Vrpm;
    sc_out<float> SpeedOut;
    sc_in<float> Vpump_fuel;
    sc_out<float> AmountFuel;


    void cal()
    {
        if (true)
        {
            if (Vrpm.read() <= 2500 && Vrpm.read() >= 500)
            {

                SpeedOut.write(Vrpm.read() / 10 - 50);
                if (Vpump_fuel.read() >= 100 && Vpump_fuel.read() <= 500)
                {
                    AmountFuel.write(Vpump_fuel.read() / 100);
                }
            }
            else if (Vrpm.read() < 500)
            {
                cout << " Van toc quay cua dong co khong dat toc do de xe di chuyen" << endl;
                SpeedOut.write(0);
                AmountFuel.write(0);
            }
            else
            {
                cout << " Van toc quay qua tai cua he thong " << endl;
            }

            wait(1, SC_SEC);
            cout << sc_time_stamp() << "\t Vrpm = " << Vrpm.read() << " (vong/phut) \t SpeedOut = " << SpeedOut.read() << " (km/h) " << endl;
            cout << sc_time_stamp() << "\t Vpump = " << Vpump_fuel.read() << " (vong/phut) \t AmountFuel = " << AmountFuel.read() << " (mL/phut) " << endl;
            
        }

        
            
    }

    void state(){
        
         while(true) {
            int a ;
            
            cout << "\n\t1. Khoi dong dong co\n\t2. Van toc binh thuong(tang toc)\n\t3.Van toc cao(tang toc)\n\t4. Giam toc do \n\n Moi nhap trang thai: ";
            cin>>a;
        
             switch(a){  
                    
              case 1: 
               
                for(int  i = 0 ; i <= 50; i++) {
    
                r[i]=InfoCar(10 * i, 10*i/ 5, ((float)std::rand() / RAND_MAX) * (5 - 3) + 3);
                
                wait(10,SC_SEC);
                cout <<sc_time_stamp()<< "\tV_rpm = " << r[i].getVrpm() << "(v/p)\t\tSpeed_t = " << 0 <<"km/h" << endl;
                cout <<sc_time_stamp()<< "\tV_fuel = " << r[i].getVpump_fuel() << "(v/p)" << endl;
                cout <<sc_time_stamp()<< "\tP_before = " << r[i].getIndexPressure() << "(kg/cm2)\tP_after = " << ((float)std::rand() / RAND_MAX) * (4.2 - 3.8) + 3.8<<"kg/cm2\n" << endl;
            } 
            
                
            case 2:
            
                for(int  i = 50 ; i <= 100; i++) {
    
                r[i]=InfoCar(10 * i, 10*i/ 5, ((float)std::rand() / RAND_MAX) * (5 - 3) + 3);
    
    
                wait(10,SC_SEC);
                cout <<sc_time_stamp()<< "\tV_rpm = " << r[i].getVrpm() << "(v/p)\t\tSpeed_t = " << r[i].getVrpm() / 10 - 50 <<"km/h" << endl;
                cout <<sc_time_stamp() <<"\tV_fuel = " << r[i].getVpump_fuel() << "(v/p)"<< endl;
                cout <<sc_time_stamp()<< "\tP_before = " << r[i].getIndexPressure() << "(kg/cm2)\tP_after = " << ((float)std::rand() / RAND_MAX) * (4.2 - 3.8) + 3.8<<"kg/cm2\n" << endl;
            }
            case 3: 
        
            for(int  i = 100 ; i <= 150; i++) {
    
                r[i]=InfoCar(10 * i, 10*i/ 5, ((float)std::rand() / RAND_MAX) * (5 - 3) + 3);
    
    
                wait(10,SC_SEC);
                cout <<sc_time_stamp()<< "\tV_rpm = " << r[i].getVrpm() << "(v/p)\t\tSpeed_t = " << r[i].getVrpm() / 10 - 50 <<"km/h" << endl;
                cout <<sc_time_stamp() <<"\tV_fuel = " << r[i].getVpump_fuel() << "(v/p)"  << endl;
                cout <<sc_time_stamp()<< "\tP_before = " << r[i].getIndexPressure() << "(kg/cm2)\tP_after = " << ((float)std::rand() / RAND_MAX) * (4.2 - 3.8) + 3.8<<"kg/cm2\n" << endl;
            }

            case 4: 
        
            for(int  i = 200 ; i >= 150; i--) {
    
                r[i]=InfoCar(10 * i, 10*i/ 5, ((float)std::rand() / RAND_MAX) * (5 - 3) + 3);
    
    
                wait(10,SC_SEC);
                cout <<sc_time_stamp()<< "\tV_rpm = " << r[i].getVrpm() << "(v/p)\t\tSpeed_t = " << r[i].getVrpm() / 10 - 50 <<"km/h" << endl;
                cout <<sc_time_stamp() <<"\tV_fuel = " << r[i].getVpump_fuel() << "(v/p)" << endl;
                cout <<sc_time_stamp()<< "\tP_before = " << r[i].getIndexPressure() << "(kg/cm2)\tP_after = " << ((float)std::rand() / RAND_MAX) * (4.2 - 3.8) + 3.8<<"kg/cm2\n" << endl;
            }
            }
    }
             
            
        
    }

    

    SC_CTOR(calculate)
    {
        SC_THREAD(cal);
        SC_THREAD(state);
        sensitive << Vrpm;
        sensitive << Vpump_fuel;
    }

};
SC_MODULE(Pressure)
{
    sc_in<float> Vpump_fuel;
    sc_in<float> IndexPressure;
    sc_out<float> SatisfactoryPressure;
    

    void pressure_balance()
    {
        if (true)
        {
            float z;
            std::srand(std::time(NULL));
            z = ((float)std::rand() / RAND_MAX) * (4.2 - 3.8) + 3.8;

            if (IndexPressure.read() >= 3.8 && IndexPressure.read() <= 4.2)
            {

                SatisfactoryPressure.write(IndexPressure.read());
            }
            else if (IndexPressure.read() < 5 && IndexPressure.read() >= 3)
            {
                SatisfactoryPressure.write(z);
            }

            else
            {

                SatisfactoryPressure.write(false);
            }
           wait(1, SC_SEC); 

           cout << sc_time_stamp() << "\tAp suat truoc khi on dinh: " << IndexPressure.read() << "(kg/cm2) \n\tAp suat sau khi on dinh: " << SatisfactoryPressure.read() << " (kg/cm2) " << endl
                 << "\n";
                
        }
        
          
    }

    SC_CTOR(Pressure)
    {
        SC_THREAD(pressure_balance);
        sensitive << IndexPressure;
        sensitive << Vpump_fuel;
    }
};


int sc_main(int argc, char *argv[])
{
    sc_signal<float> Vrpm;
    sc_signal<float> SpeedOut;
    sc_signal<float> Vpump_fuel;

    sc_signal<float> AmountFuel;
    sc_signal<float> IndexPressure;
    sc_signal<float> SatisfactoryPressure;
    std::srand(std::time(NULL));
    InfoCar a(2500,300,((float)std::rand() / RAND_MAX) * (5 - 3) + 3);
    

    
   
    
    
    Vrpm = a.getVrpm();
    Vpump_fuel = a.getVpump_fuel();
    IndexPressure = a.getIndexPressure();
    
   

    calculate cal("calculate");
    cal.Vrpm(Vrpm);
    cal.SpeedOut(SpeedOut);
    cal.Vpump_fuel(Vpump_fuel);
    cal.AmountFuel(AmountFuel);

    Pressure press("Pressure");
    press.Vpump_fuel(Vpump_fuel);
    press.IndexPressure(IndexPressure);
    press.SatisfactoryPressure(SatisfactoryPressure);

    cout << "\n \t HE THONG DIEU KHIEN BOM XANG TRONG O TO \n\n"
         << endl;
   

    sc_start(510, SC_SEC);
    return 0;
}