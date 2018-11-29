Fs = 2000;
t = 0:1/Fs:pi;
x = cos(2*pi*t);
y = sin(2*pi*t);
stem3(t,x,y);