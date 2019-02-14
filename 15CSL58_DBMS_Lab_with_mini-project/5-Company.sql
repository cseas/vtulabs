create table employee
(
	ssn varchar(10),
	name varchar(10),
	salary number(8),
	superssn varchar(10),
	dno number(1),
	constraint pk_ssn primary key(ssn) 
);

create table department
(
	dno number(1),
	dname varchar(15),
	mgrssn varchar(10),
	constraint pk_dno primary key(dno),
	constraint fk_ssn foreign key(mgrssn) references employee(ssn) on delete cascade
);

create table project
(
	pno number(2),
	pname varchar(15),
	dno number(1),
	constraint pk_pno primary key(pno),
	constraint fk_dno foreign key(dno) references department(dno) on delete cascade
);

create table works_on
(
	ssn varchar(10),
	pno number(2),
	constraint cpk_ssnpno primary key(ssn, pno),
	constraint fk_ssn1 foreign key(ssn) references employee(ssn) on delete cascade,
	constraint fk_pno foreign key(pno) references project(pno) on delete cascade
);

insert into employee values ('&ssn', '&name', &salary, '&superssn', &dno);
insert into department values (&dno, '&dname', '&mgrssn');
insert into project values (&pno, '&pname', &dno);
insert into works_on values ('&ssn', &pno); 
alter table employee add constraint fk_dno11 foreign key(dno) references department(dno) on delete cascade;

(select distinct p.pno
from project p, employee e, department d
where e.ssn=d.mgrssn and d.dno = p.dno and e.name = 'scott')
union
(select distinct p.pno
from project p, employee e, works_on w
where e.ssn=w.ssn and p.pno=w.pno and e.name='scott');

select e.name, 1.1*e.salary as hike_sal
from employee e, works_on w, project p
where e.ssn=w.ssn and p.pno=w.pno
and p.pname='Deep';

select sum(e.salary) as sum_sal, max(e.salary) as max_sal, avg(e.salary) as avg_sal, min(e.salary) as min_sal
from employee e, department d
where d.dno=e.dno and d.dname='IoT';

select e.name
from employee e where 
not exists((select p.pno from project p where p.dno=5)minus(select w.pno from works_on w where e.ssn=w.ssn));

select dno, count(*) as no_of_emp
from employee 
where salary > 600000
and dno in (select e.dno from employee e group by e.dno having count(*)>5)
group by dno;