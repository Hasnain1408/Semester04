CREATE TABLE Taken(
    Student VARCHAR(10),
    Course VARCHAR(50)
);

INSERT INTO Taken VALUES('Robert','Databases');
INSERT INTO Taken VALUES('Robert'  ,'Programming Languages');
INSERT INTO Taken VALUES('Susie' ,'Databases');
INSERT INTO Taken VALUES( 'Susie' ,'Operating Systems');
INSERT INTO Taken VALUES('Julie' ,'Programming Languages');
INSERT INTO Taken VALUES('Julie' ,'Machine Learning');
INSERT INTO Taken VALUES( 'Emilie','Operating Systems');


CREATE TABLE Required(
    Course VARCHAR(50)
);

INSERT INTO Required VALUES('Databases');
INSERT INTO Required VALUES('Programming Languages');