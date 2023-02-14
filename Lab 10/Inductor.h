// Inductor.h - class declaration for the inductor

class Inductor {
    double inductance;
    double current;

   public:
    Inductor(double);
    double GetCurrent(double, double);
};
