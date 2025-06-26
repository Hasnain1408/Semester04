CREATE TABLE branch(
    branch_name VARCHAR(20),
    branch_city VARCHAR(20), 
    assets NUMBER(10),
    PRIMARY KEY (branch_name)
);

-- INSERT into branch VALUES ('IBBL', 'Uttara', 1000000);
-- INSERT into branch VALUES ('DBBL', 'Mirpur', 1500000);
-- INSERT into branch VALUES ('Sonali', 'Motijheel', 900000);

insert into Branch values('Brighton','Brooklyn',7100000);
insert into Branch values('Downtown','Brooklyn',9000000);
insert into Branch values('Mianus','Horseneck',400000);
insert into Branch values('North Town','Rye',3700000);
insert into Branch values('Perryridge','Horseneck',1700000);
insert into Branch values('Pownal','Bennington',300000);
insert into Branch values('Redwood','Polo Alto',2100000);
insert into Branch values('Round Hill','Horseneck',8000000);

CREATE TABLE customer(
    customer_name VARCHAR(20),
    loan_number VARCHAR(20),
    balance NUMBER(10),
    PRIMARY KEY (customer_name)
);

-- INSERT into customer VALUES ('Hasnain','Kotalipara', 'Gopalgonj');
-- INSERT into customer VALUES ('Sami', 'Dhanmondi', 'Dhaka');
-- INSERT into customer VALUES ('Rifat', 'Talora', 'Bogura');

insert into customer values ('Adams','L-16',1300);
insert into customer values ('Curry','L-93',500);
insert into customer values ('Hayes','L-15',1500);
insert into customer values ('Jackson','L-14',1500);
insert into customer values ('Jones','L-17',1000);
insert into customer values ('Smith','L-23',2000);
insert into customer values ('Smith','L-11',1300);
insert into customer values ('Williams','L-17',1000);

CREATE TABLE account(
    account_number NUMBER(10),
    branch_name VARCHAR(20),
    balance NUMBER(10),
    PRIMARY KEY (account_number),
    FOREIGN KEY (branch_name) REFERENCES  branch(branch_name)
);

-- INSERT into account VALUES (1408, 'IBBL', 10000);
-- INSERT into account VALUES (1409, 'DBBL', 15000);
-- INSERT into account VALUES (1410, 'Sonali', 15000);

insert into account values ('A-101','Downtown',500);
insert into account values ('A-102','Perryridge',400);
insert into account values ('A-201','Brighton',900);
insert into account values ('A-215','Mianus',700);
insert into account values ('A-217','Brighton',750);
insert into account values ('A-222','Redwood',700);
insert into account values ('A-305','Round Hill',350);

CREATE TABLE loan(
    loan_number VARCHAR(20),
    branch_name VARCHAR(20),
    amount NUMBER(10),
    PRIMARY KEY (loan_number),
    FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

-- INSERT into loan VALUES ('L-1001', 'IBBL', 100000);
-- INSERT into loan VALUES ('L-1002', 'DBBL', 150000);
-- INSERT into loan VALUES ('L-1003', 'Sonali', 50000);

insert into loan values('L-11','Round Hill',900);
insert into loan values('L-14','Downtown',1500);
insert into loan values('L-15','Perryridge',1500);
insert into loan values('L-16','Perryridge',1300);
insert into loan values('L-17','Downtown',1000);
insert into loan values('L-23','Redwood',2000);
insert into loan values('L-93','Mianus',500);

CREATE TABLE depositor(
    customer_name VARCHAR(20),
    account_number VARCHAR(10),
    PRIMARY KEY (customer_name, account_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (account_number) REFERENCES account(account_number)
);

-- INSERT into depositor VALUES ('Hasnain', 1408);
-- INSERT into depositor VALUES ('Sami', 1409);
-- INSERT into depositor VALUES ('Rifat', 1410);

insert into depositor values ('Hayes','A-102');
insert into depositor values ('Johnson','A-101');
insert into depositor values ('Johnson','A-201');
insert into depositor values ('Jones','A-217');
insert into depositor values ('Lindsay','A-222');
insert into depositor values ('Smith','A-215');
insert into depositor values ('Turner','A-305');

CREATE TABLE borrower(
    customer_name VARCHAR(20),
    loan_number VARCHAR(20),
    PRIMARY KEY (customer_name, loan_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (loan_number) REFERENCES loan(loan_number)
);

-- INSERT into borrower VALUES ('Sami', 'L-1002');
-- INSERT into borrower VALUES ('Hasnain', 'L-1001');
-- INSERT into borrower VALUES ('Rifat', 'L-1003');

insert into borrower values ('Adams','L-26');
insert into borrower values ('Curry','L-93');
insert into borrower values ('Hayes','L-15');
insert into borrower values ('Jackson','L-14');
insert into borrower values ('Jones','L-17');
insert into borrower values ('Smith','L-11');
insert into borrower values ('Smith','L-23');
insert into borrower values ('Williams','L-17');