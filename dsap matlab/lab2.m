sgtitle('Mahim KCE077BCT019') 

n = 0:1:10; 
x=1:11;
for i = 1:length(n)
    if n(i) >= 2 && n(i) <= 6 
        x(i) = 1;
    else
        x(i) = 0;
    end
end
% % 
subplot(4,2,1);
stem(n,x);
xlim([0,10]);
ylim([-1,4]);
grid on;
xlabel('Time period');
ylabel('Amplitude');
title('Original Signal')
% % % % 
subplot(4,2,2);
stem(n,fliplr(x));
xlim([0,10]);
ylim([-1,4]);
grid on;
xlabel('Time period');
ylabel('Amplitude');
title('Flipped Signal')
% % % % 
scale=2;
subplot(4,2,3);
stem(n/scale,x);
xlim([0,10]);
ylim([-1,4]);
grid on;
xlabel('Time period');
ylabel('Amplitude');
title('Time scale compression by 2')
% % % % 
subplot(4,2,4);
stem(n*scale,x);
xlim([0,20]);
ylim([-1,4]);
grid on;
xlabel('Time period');
ylabel('Amplitude');
title('time scale expansion by 2')
% % % % 
scale=-3;
subplot(4,2,5);
stem(n-scale,x);
xlim([0,10]);
ylim([-1,4]);
grid on;
xlabel('Time period');
ylabel('Amplitude');
title('Delay Signal by 2')
% % % % 
subplot(4,2,6);
stem(n+scale,x);
xlim([0,10]);
ylim([-1,4]);
grid on;
xlabel('Time period');
ylabel('Amplitude');
title('Advance Signal by 2')

% % % 2x[-2n+3]
subplot(4,2,7);
shift= n-3
flip =  -shift;
scale = 2*flip
amp= 2*x ;
stem (scale, amp) ;
xlabel('Time period');
ylabel('Amplitude');
title ('2x[-2n+3] transform');
xlim([-15,10]);
ylim([-1,4]);
grid on;


