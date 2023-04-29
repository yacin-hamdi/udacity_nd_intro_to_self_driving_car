#pragma once

class Gaussian{
    public:
        Gaussian();
        Gaussian(float, float);

        void setMu(float mu);
        void setSigma2(float segma);
        float getMu();
        float getSigma2();

        float evaluate(float x);
        Gaussian multiply(Gaussian other);
        Gaussian add(Gaussian other);



    private:
        float sigma2_;
        float mu_;
};