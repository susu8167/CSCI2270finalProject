data=csvread("insert_linkedList.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

figure;
plot(x,y);
hold on;

data=csvread("search_linkedList.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

hold on;
plot(x,y)
legend("insert","search");
title("LinkedList");
xlabel("index (x100)");
ylabel("time consumed");






data=csvread("insert_bst.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

figure;
plot(x,y);
hold on;

data=csvread("search_BST.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

hold on;
plot(x,y)
legend("insert","search");
title("BST");
xlabel("index (x100)");
ylabel("time consumed");







data=csvread("insert_hashChaining.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

figure;
yyaxis left;
plot(x,y,'-g');
hold on;

data=csvread("search_hashChaining.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

plot(x,y,'-r')
legend("insert","search");
title("hashChaining");
xlabel("index (x100)");
ylabel("time consumed");

yyaxis right;

data = csvread("insertCollision_hashChaining.csv");
x=data(:,1);
y=data(:,2);
plot(x,y,'-b');

data = csvread("searchCollision_hashChaining.csv");
x=data(:,1);
y=data(:,2);
plot(x,y,'-y');
ylabel("number of collisions");

legend("insert","search","insertCollision","searchCollision");







data=csvread("insert_hashLinear.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

figure;

yyaxis left;
plot(x,y,'g-');
hold on;

data=csvread("search_hashLinear.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

plot(x,y,'-r')
legend("insert","search");
title("hashLinear");
xlabel("index (x100)");
ylabel("time consumed");

yyaxis right;

data = csvread("insertCollision_hashLinear.csv");
x=data(:,1);
y=data(:,2);
plot(x,y,'-b');

data = csvread("searchCollision_hashLinear.csv");
x=data(:,1);
y=data(:,2);
plot(x,y,'-y');
ylabel("number of collisions");

legend("insert","search","insertCollision","searchCollision");








data=csvread("insert_hashQuadratic.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

figure;

yyaxis left;
plot(x,y,'g-');
hold on;

data=csvread("search_hashQuadratic.csv"); % reading csv file 
x=data(:,1); % reading its first column
y=data(:,2); % reading its second column of csv file

plot(x,y,'r-')
title("hashQuadratic");
xlabel("index (x100)");
ylabel("time consumed");
ylim([10^-10,10^-7])

yyaxis right;

data = csvread("insertCollision_hashQuadratic.csv");
x=data(:,1);
y=data(:,2);
plot(x,y,'b-');

data = csvread("searchCollision_hashQuadratic.csv");
x=data(:,1);
y=data(:,2);
plot(x,y,'y-');
ylabel("number of collisions");

legend("insert","search","insertCollision","searchCollision");

