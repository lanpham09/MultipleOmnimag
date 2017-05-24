clear;
clc;

% omnimagent_moment = dlmread('Omnimagnet Dipole Moment.csv',',',3,0);
% capsule_pos = dlmread('Tool Location in WORLD_FRAME.csv',',',3,0);
% goal_pos = dlmread('Goal Location.csv',',',3,0);
% inner_current = dlmread('AMC A-INNER Current Measurement.csv',',',3,0);
% inner_commandVolts = dlmread('AMC A Command.csv',',',3,0);
% inner_commandAmps = dlmread('AMC A-INNER Current Output.csv',',',3.0);
% middle_current = dlmread('AMC B-MIDDLE Current Measurement.csv',',',6,0);
% middle_commandVolts = dlmread('AMC B Command.csv',',',3,0);
% middle_commandAmps = dlmread('AMC B-MIDDLE Current Output.csv',',',3.0);
% outer_current = dlmread('AMC C-OUTER Current Measurement.csv',',',3.0);
% outer_commandVolts = dlmread('AMC C Command.csv',',',3,0);
% outer_commandAmps = dlmread('AMC C-OUTER Current Output.csv',',',3.0);
goal_RightPix = dlmread('Goal Right Pixel Location.csv',',',3.0);
goal_LeftPix = dlmread('Goal Left Pixel Location.csv',',',3.0);

% tool_RightPix = dlmread('Right Pixel Location.csv',',',3.0);
% tool_LeftPix = dlmread('Left Pixel Location.csv',',',3.0);


%%

readerobjRight = VideoReader('Right Video Stream.avi');
readerobjLeft = VideoReader('Left Video Stream.avi');
numFrames = get(readerobjRight, 'NumberOfFrames');

%%
trajectory = zeros(readerobjRight.Height,readerobjRight.Width,3,'uint8');
trajectory2 = zeros(readerobjLeft.Height,readerobjLeft.Width,3,'uint8');

w = 1;
for i=250:1450
    trajectory(round(goal_LeftPix(i,3))+(-w:1:w),round(goal_LeftPix(i,2))+(-w:1:w),1) = 50;
    trajectory(round(goal_LeftPix(i,3))+(-w:1:w),round(goal_LeftPix(i,2))+(-w:1:w),2) = 50;
    trajectory(round(goal_LeftPix(i,3))+(-w:1:w),round(goal_LeftPix(i,2))+(-w:1:w),3) = 50;
end
for i=1450:2690
    trajectory2(round(goal_RightPix(i,3))+(-w:1:w),round(goal_RightPix(i,2))+(-w:1:w),1) = 50;
    trajectory2(round(goal_RightPix(i,3))+(-w:1:w),round(goal_RightPix(i,2))+(-w:1:w),2) = 50;
    trajectory2(round(goal_RightPix(i,3))+(-w:1:w),round(goal_RightPix(i,2))+(-w:1:w),3) = 50;
end
figure(1)
clf;
image(trajectory)
figure(2)
clf;
image(trajectory2)
%%
writer =VideoWriter('OutputFile.avi');
open(writer);
for k = 100 : 2690
    vidFramesRight = read(readerobjRight,k);
    vidFramesLeft = read(readerobjLeft,k);
    if( k < 1450 )
        vidFramesRight = vidFramesRight-trajectory;
    else
        vidFramesLeft = vidFramesLeft-trajectory2;
    end
        
    mov.cdata = [vidFramesRight,zeros(480,3,3),vidFramesLeft];
    mov.colormap = [];
    
    writeVideo(writer,mov);
end

close(writer);

%%
% hf = figure;
% 
% set(hf, 'position', [150 150 readerobjRight.Width readerobjRight.Height])
% movie(hf, mov, 1, readerobjRight.FrameRate);
%%



% OmnimagPos = [520.3635, -25.228525, 9.78525]';
% AMC_AperV = 1/0.5993;
% 
% figure(1)
% subplot(3,1,1)
% plot(inner_current(:,1),inner_current(:,2),'og', inner_commandAmps(:,1),inner_commandAmps(:,2),'-k',inner_commandVolts(:,1),inner_commandVolts(:,2)*AMC_AperV,'r')
% ylabel('Inner Current Amps');
% subplot(3,1,2)
% plot(middle_current(:,1),middle_current(:,2),'og', middle_commandAmps(:,1),middle_commandAmps(:,2),'-k',middle_commandVolts(:,1),middle_commandVolts(:,2)*AMC_AperV,'r')
% ylabel('Middle Current Amps');
% subplot(3,1,3)
% plot(outer_current(:,1),outer_current(:,2),'og', outer_commandAmps(:,1),outer_commandAmps(:,2),'-k',outer_commandVolts(:,1),outer_commandVolts(:,2)*AMC_AperV,'r')
% ylabel('Outer Current Amps');
% 
% figure(2)
% subplot(3,1,1)
% plot(capsule_pos(:,1),capsule_pos(:,2),'.',goal_pos(:,1),goal_pos(:,2),'k')
% subplot(3,1,2)
% plot(capsule_pos(:,1),capsule_pos(:,3),'.',goal_pos(:,1),goal_pos(:,3),'k')
% subplot(3,1,3)
% plot(capsule_pos(:,1),capsule_pos(:,4),'.',goal_pos(:,1),goal_pos(:,4),'k')