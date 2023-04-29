#include"gaussian.h"
#include<cmath>

Gaussian::Gaussian(){
    this->mu_ = 0;
    this->sigma2_ = 1;
}

Gaussian::Gaussian(float mu, float sigma2){
    this->mu_ = mu;
    this->sigma2_ = sigma2;
}

void Gaussian::setMu(float mu){
    this->mu_ = mu;
}

void Gaussian::setSigma2(float sigma2){
    this->sigma2_ = sigma2;
}

float Gaussian::getMu(){
    return this->mu_;
}

float Gaussian::getSigma2(){
    return this->sigma2_;
}

float Gaussian::evaluate(float x){
    float coefficient = 1 / sqrt(2 * M_PI * this->sigma2_);
    float exponential = exp(-0.5 * pow((x-this->mu_),2) / this->sigma2_);
    return coefficient * exponential;
}

Gaussian Gaussian::add(Gaussian other){
    float new_mu = this->mu_ + other.mu_;
    float new_sigma2 = this->sigma2_ + other.sigma2_;
    return Gaussian(new_mu, new_sigma2);
}

Gaussian Gaussian::multiply(Gaussian other){
    float denominator = this->sigma2_ + other.sigma2_;
    float numerator = this->mu_ * other.sigma2_ + other.mu_ + this->sigma2_;
    float new_mu = numerator / denominator;

    float new_var = 1 / ((1/this->sigma2_) + (1 / other.sigma2_));
    return Gaussian(new_mu, new_var);

}