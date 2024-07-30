% x = input('Enter x[n]:');
% h = input('Enter h[n]:');
x = [1,2,1,2];
h = [1,1,1];
xo = input('Enter position of 1st term x[n]:');
ho = input('Enter position of 1st term h[n]:');
lx = length(x);
lh = length(h);

xn = xo+lx-1;
n1 = xo:xn;

hn = ho+lh-1;
n2 = ho:hn;


sgtitle('Unique KCE077BCT045') 

subplot(2,2,1);
stem(n1,x);
xlim([-3, 6])
ylim([-3, 3])
title('x[k]');
grid on;

subplot(2,2,3);
stem(n2,h);
xlim([-3, 6])
ylim([-3, 3])
title('h[k]');
grid on;

y = conv(x,h);

% Plotting the convolution result
subplot(2,2,[2,4]);
ny = xo+ho:xn+hn(end); 
stem(ny,y);
grid on;
xlabel('n');
ylabel('y[n]');
xlim([-5,10]);
ylim([-5,10]);
title('Convolution Result');
