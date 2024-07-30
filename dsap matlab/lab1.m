sgtitle('Unique KCE077BCT045') 
%impulse
n = -10:10;
for i = 1:21
    if n(i)==0
        x(i) = 1 ;
    else
        x(i) = 0;
    end
end
subplot(3,2,1)
stem(n,x)
xlabel('x[n]');
ylabel('n');
y_max = max(x);
ylim([-1 y_max + 1]);
title('impulse signal');
       
%unit

n = -10:10;
for i = 1:21
    if n(i) >= 0
        x(i) = 1 ;
    else
        x(i) = 0;
    end
end
subplot(3,2,2)
stem(n,x)
xlabel('x[n]');
ylabel('n');
ylim([-1 y_max + 1]);
title('unit-step signal');

%ramp
n = -10:10;
for i = 1:21
    if n(i) > 0
        x(i) = n(i);
    else
        x(i) = 0;
    end
end
subplot(3,2,3);
stem(n, x);
xlabel('x[n]');
ylabel('n');
ylim([-5 y_max + 15]);

title('Ramp Signal');

%sinusoidal
for i = 1:21
        x(i) = sin(i)
end
subplot(3,2,4);
stem(n, x);
xlabel('x[n]');
ylabel('n');
ylim([-2 y_max + 1]);
title('sinusoidal Signal');


%exponential  
for i = 1:21
        x(i) = exp(i)
end
subplot(3,2,5);
stem(n, x);
xlabel('x[n]');
ylabel('n');
ylim([-5*10^8 max(x)]);
title('exponential Signal');


%signum

n = -10:10;
for i = 1:21
    if n(i) > 0
        x(i) = 1 ;
    elseif n(i) < 0
        x(i) = -1 ;
    else
        x(i) = 0;
    end
end
subplot(3,2,6)
stem(n,x)
xlabel('x[n]');
ylabel('n');
ylim([-2 y_max + 1]);
title('signum signal');

 