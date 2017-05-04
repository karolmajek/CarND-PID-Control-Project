#include "PID.h"
#include <cstdio>

using namespace std;

PID::PID()
{
    Kp=Ki=Kd=0;
    p_error = i_error = d_error = 0.0001;
    best_cte = prev_cte = 9999999;
    diff_cte = int_cte = 0;
}

PID::~PID()
{
}

void PID::Init(double Kp, double Ki, double Kd)
{
    this->Kp=Kp;
    this->Ki=Ki;
    this->Kd=Kd;
}

void PID::UpdateError(double cte)
{
    diff_cte = cte - prev_cte;
    prev_cte = cte;
    /*
    if (cte<best_cte)
    {
        best_cte=cte;

        Kp += p_error;
        Ki += i_error;
        Kd += d_error;

        p_error *= 1.1;
        i_error *= 1.1;
        d_error *= 1.1;

    }
    else
    {

        p_error *= 0.9;
        i_error *= 0.9;
        d_error *= 0.9;

        Kp -= p_error;
        Ki -= i_error;
        Kd -= d_error;
    }
    printf("PID: %f %f %f\n",Kp,Ki,Kd);*/
}

double PID::TotalError()
{
    double out = -Kp * prev_cte - Kd * diff_cte - Ki * int_cte;

    return out;
}

