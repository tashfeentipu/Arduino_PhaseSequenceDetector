#include <CComplex.h>

Complex i1(0, 0);
Complex i2(0, 0);
Complex i3(0, 0);

Complex a(0, 0);

Complex ps(0, 0);
Complex ns(0, 0);
Complex zs(0, 0);
intnlc=30, slg=31, dlg=32, ll=40, lll=34;
floati_PickUp=0, OverLoad=0.1, i_Normal=73.1;

void setup()
{
Serial.begin(115200);

pinMode(nlc, OUTPUT);
pinMode(slg, OUTPUT);
pinMode(dlg, OUTPUT);
pinMode(ll, OUTPUT);
pinMode(lll, OUTPUT);

i_PickUp = i_Normal + (i_Normal*OverLoad);

a.polar((float)1, (float)2.0944);
i1.polar(0, (0*(0.01745329252)));
i2.polar(1233, (154.21*(0.01745329252)));
i3.polar(1207, (50.72*(0.01745329252)));

if((i1.modulus()>i_PickUp) || (i2.modulus()>i_PickUp) || (i3.modulus()>i_PickUp))
  { 
zs = (i1 + i2 + i3)/3;
ps = (i1 + a*i2 + (a*a)*i3)/3;
ns = (i1 + (a*a)*i2 + a*i3)/3;

if((zs==ps) && (ps==ns))
    {   
digitalWrite(slg,1); 
Serial.println("Single Line to Ground (L-G) Fault Detected in the System.\n"); 

Serial.print("Ia : "); Serial.print(i1.modulus(), 2);  Serial.print("<"); Serial.print(i1.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ib : "); Serial.print(i2.modulus(), 2);  Serial.print("<"); Serial.print(i2.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ic : "); Serial.print(i3.modulus(), 2);  Serial.print("<"); Serial.print(i3.phase()*57.2957795131); Serial.println(" Amps.\n");

Serial.print("Zero Sequence Component: "); Serial.print(zs.modulus(), 2);  Serial.print("<"); Serial.print(zs.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Positive Sequence Component: "); Serial.print(ps.modulus(), 2);  Serial.print("<"); Serial.print(ps.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Negative Sequence Component: "); Serial.print(ns.modulus(), 2);  Serial.print("<"); Serial.print(ns.phase()*57.2957795131); Serial.println(" Amps.");
    }
  else if((int)zs.modulus()==0 && (int)ps.modulus()==(int)ns.modulus())
    {
digitalWrite(ll,1);
Serial.println("Line to Line (L-L) Fault Detected in the System.\n");

Serial.print("Ia : "); Serial.print(i1.modulus(), 2);  Serial.print("<"); Serial.print(i1.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ib : "); Serial.print(i2.modulus(), 2);  Serial.print("<"); Serial.print(i2.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ic : "); Serial.print(i3.modulus(), 2);  Serial.print("<"); Serial.print(i3.phase()*57.2957795131); Serial.println(" Amps.\n");

Serial.print("Zero Sequence Component: "); Serial.print(zs.modulus(), 2);  Serial.print("<"); Serial.print(zs.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Positive Sequence Component: "); Serial.print(ps.modulus(), 2);  Serial.print("<"); Serial.print(ps.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Negative Sequence Component: "); Serial.print(ns.modulus(), 2);  Serial.print("<"); Serial.print(ns.phase()*57.2957795131); Serial.println(" Amps.");
    }
else if((int)ns.modulus()==0 && (int)zs.modulus()==0)
    {
digitalWrite(lll,1);
Serial.println("Three-Phase (L-L-L) Fault Detected in the System.\n");

Serial.print("Ia : "); Serial.print(i1.modulus(), 2);  Serial.print("<"); Serial.print(i1.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ib : "); Serial.print(i2.modulus(), 2);  Serial.print("<"); Serial.print(i2.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ic : "); Serial.print(i3.modulus(), 2);  Serial.print("<"); Serial.print(i3.phase()*57.2957795131); Serial.println(" Amps.\n");

Serial.print("Zero Sequence Component: "); Serial.print(zs.modulus(), 2);  Serial.print("<"); Serial.print(zs.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Positive Sequence Component: "); Serial.print(ps.modulus(), 2);  Serial.print("<"); Serial.print(ps.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Negative Sequence Component: "); Serial.print(ns.modulus(), 2);  Serial.print("<"); Serial.print(ns.phase()*57.2957795131); Serial.println(" Amps.");
    }
else
    { 
digitalWrite(dlg,1);
Serial.println("Double Line to Ground (L-L-G) Fault Detected in the System.\n");

Serial.print("Ia : "); Serial.print(i1.modulus(), 2);  Serial.print("<"); Serial.print(i1.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ib : "); Serial.print(i2.modulus(), 2);  Serial.print("<"); Serial.print(i2.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ic : "); Serial.print(i3.modulus(), 2);  Serial.print("<"); Serial.print(i3.phase()*57.2957795131); Serial.println(" Amps.\n");

Serial.print("Zero Sequence Component: "); Serial.print(zs.modulus(), 2);  Serial.print("<"); Serial.print(zs.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Positive Sequence Component: "); Serial.print(ps.modulus(), 2);  Serial.print("<"); Serial.print(ps.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Negative Sequence Component: "); Serial.print(ns.modulus(), 2);  Serial.print("<"); Serial.print(ns.phase()*57.2957795131); Serial.println(" Amps.");
    }
  }
else
{
digitalWrite(nlc,1);

Serial.print("Ia : "); Serial.print(i1.modulus(), 2);  Serial.print("<"); Serial.print(i1.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ib : "); Serial.print(i2.modulus(), 2);  Serial.print("<"); Serial.print(i2.phase()*57.2957795131); Serial.println(" Amps.");
Serial.print("Ic : "); Serial.print(i3.modulus(), 2);  Serial.print("<"); Serial.print(i3.phase()*57.2957795131); Serial.println(" Amps.\n");

Serial.print("The Power System is running under normal load conditions, thus no fault is detected and the relay will not trip.");
}}


