data=csvread("search_linkedList.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

plot(x,y);
hold on;

data=csvread("search_bst.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

plot(x,y);
hold on;

data=csvread("search_hashLinear.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

plot(x,y);
hold on;
legend("LL","BST","HL");
title("SearchB");
xlabel("index (x100)");
ylabel("time consumed");
ylim([0,10^-6]);


