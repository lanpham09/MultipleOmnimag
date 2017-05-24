clear;
clc

camFrameRate = 30;%hz
P = .05;
D = .25;
I = 0*P/200;
pole = 5*2*pi;
controller = tf([D+P,P*pole],[1,pole])%zpk(-3.5,-35,1)
discCont = c2d(controller,1/camFrameRate,'zoh')
[Z,P,K,T] = zpkdata(discCont);

randPosError = (rand(3,1)-.5)*3/1000

%%
timeToComplete = 80;
ts = .1;

num =length(0:ts:timeToComplete);
theta = linspace(3*pi/4,2*pi+3*pi/4,num)';
r = 4*cos(2*theta);
x = r.*cos(theta);
y=r.*sin(theta)+5.5;
diffX = [x(2:num)-x(1:(num-1));x(1)-x(num);];
diffY = [y(2:num)-y(1:(num-1));y(1)-y(num);];
quiver(x,y,diffX,diffY)
% Xlist = [[0,10,15:ts:75]',[0,x(1)/100,x'/100]'];
% Ylist = [[0,10,15:ts:75]',[zeros(size([0,10,15:ts:75]))]'];
% Zlist = [[0,10,15:ts:75]',[0,y(1)/100,y'/100]'];

Tstart = 15;
timeList = [0:ts:Tstart,Tstart:ts:(15+timeToComplete),(15+timeToComplete+5):ts:(15+2*timeToComplete+5),(15+2*timeToComplete+5+ts):ts:(15+2*timeToComplete+10)]';
size1 = size([0:ts:Tstart,Tstart:ts:(15+timeToComplete)]);
size2 = size([(15+timeToComplete+5):ts:(15+2*timeToComplete+5), (15+2*timeToComplete+5+ts):ts:(15+2*timeToComplete+10)]);

Xlist = [zeros(size(0:ts:Tstart)),x'/100,zeros(size2)]';
Ylist = [zeros(size1),x'/100,x(end)/100*ones(size((15+2*timeToComplete+5+ts):ts:(15+2*timeToComplete+10)))]';
Zlist = [linspace(0/100,y(1)/100,length(0:ts:Tstart)),y'/100,y'/100,y(end)/100*ones(size((15+2*timeToComplete+5+ts):ts:(15+2*timeToComplete+7))),linspace(y(end)/100,1/100,length((15+2*timeToComplete+7+ts):ts:(15+2*timeToComplete+10)))]';
timeList = [timeList', ((timeList(end)+1):1:(timeList(end)))]';
Trajectory = [timeList,Xlist,Ylist,Zlist];

figure(2)
subplot(3,1,1)
plot(Trajectory(:,1),Trajectory(:,2))
subplot(3,1,2)
plot(Trajectory(:,1),Trajectory(:,3))
subplot(3,1,3)
plot(Trajectory(:,1),Trajectory(:,4))

figure(3)
plot(Trajectory(:,1),Trajectory(:,2),'r',Trajectory(:,1),Trajectory(:,4),'g')


%%  Write file
fid = fopen('trajectory.csv','w');
for i = 1:length(Xlist) 
    fprintf(fid,'%6.6f, %6.6f, %6.6f\n', Xlist(i), Ylist(i), Zlist(i));
end


% struct('time',[],'signals',struct('values',[],'dimensions',[]));
% Zlist.time = [0,10,15:ts:65]';
% Zlist.signals.values=[0,y(1)/100,y'/100];
% Zlist.signals.dimensions=size(Zlist.signals.values);
%%
Xlist = struct('time',[],'signals',struct('values',[],'dimensions',[]));
Xlist.time = Zlist.time';
Xlist.signals.values =[0,x(1)/100,x'/100];
Xlist.signals.dimensions=size(Xlist.signals.dimensions);

%%



Moment = toolDipoleMoment.signals.values;
Pos = toolPosition.signals.values;
time = toolPosition.time;
timeLast = -1;

for i = find(time>9.5,1):length(Moment)
    if( time(i) > timeLast +1/60 )
    figure(1)
    subplot(2,2,1)
    plot3(Pos(:,1),Pos(:,2),Pos(:,3));
    hold on;
    moment = Moment(i,:);
    moment = moment/norm(moment)*.05;
    quiver3(Pos(i,1),Pos(i,2),Pos(i,3),moment(1),moment(2),moment(3),'k','LineWidth',2);
    hold off;
    title(['Time: ', num2str(time(i),2)])    
        axis([-.05,.05,-.05,.05,0,.3])

    
    subplot(2,2,2)
    plot(Pos(:,1),Pos(:,2));
    hold on;
    moment = Moment(i,:);
    moment = moment/norm(moment)*.05;
    quiver(Pos(i,1),Pos(i,2),moment(1),moment(2),'k','LineWidth',2);
    hold off;
    title(['X,Y Time: ', num2str(time(i),2)])    
        axis([-.05,.05,-.05,.05])

    
    subplot(2,2,3)
    plot(Pos(:,1),Pos(:,3));
    hold on;
    moment = Moment(i,:);
    moment = moment/norm(moment)*.05;
    quiver(Pos(i,1),Pos(i,3),moment(1),moment(3),'k','LineWidth',2);
    hold off;
    title(['X,Z Time: ', num2str(time(i),2)])
        axis([-.05,.05,0,.3])

    
    subplot(2,2,4)
    plot(Pos(:,2),Pos(:,3));
    hold on;
    moment = Moment(i,:);
    moment = moment/norm(moment)*.05;
    quiver(Pos(i,2),Pos(i,3),moment(2),moment(3),'k','LineWidth',2);
    hold off;
    title(['Y,Z Time: ', num2str(time(i),2)])
        axis([-.05,.05,0,.3])

    
        pause(1/60.0)
        timeLast = time(i);

    
    end
end
