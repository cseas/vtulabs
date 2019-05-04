create table actor
(
	act_id number(2),
	act_name varchar(15),
	act_gender char,
	Constraint pk_actid primary key(act_id)
);

create table director
(
	dir_id number(2),
	dir_name varchar(15),
	dir_phone number(3),
	Constraint pk_dirid primary key(dir_id)
);

create table movies
(
	mov_id number(4),
	mov_title varchar(20),
	mov_year number(4),
	mov_lang varchar(15),
	dir_id number(2),
	Constraint pk_movid primary key(mov_id),
	Constraint fk_dirid foreign key(dir_id) references director(dir_id) on delete cascade
);

create table movie_cast
(
	act_id number(2),
	mov_id number(4),
	role varchar(15),
	Constraint cpk_movact primary key(mov_id, act_id),
	Constraint fk_actid foreign key(act_id) references actor(act_id) on delete cascade,
	Constraint fk_movid foreign key(mov_id) references movies(mov_id) on delete cascade
);

create table rating
(
	mov_id number(4),
	rev_stars number(2,1),
	Constraint fk_movid1 foreign key(mov_id) references movies(mov_id) on delete cascade
);

insert into actor values (&act_id, '&act_name', '&act_gender');

insert into director values (&dir_id, '&dir_name', &dir_phone);

insert into movies values (&mov_id, '&mov_title', &mov_year, '&mov_lang', &dir_id);

insert into movie_cast (act_id, mov_id) values (&act_id, &mov_id);

insert into rating values (&mov_id, &rating);

select m.mov_title 
from movies m, director d
where d.dir_id = m.dir_id
and d.dir_name = 'hitchcock';

select a.act_id, a.act_name, m.mov_id
from actor a, movie_cast m
where a.act_id = m.act_id and a.act_id in (select act_id from movie_cast group by act_id having count(act_id) > 1 );

(select a.act_name
from actor a
join movie_cast m on
a.act_id = m.act_id
join movies m1 on
m.mov_id = m1.mov_id
where m1.mov_year < 2000)
intersect
(select a1.act_name
from actor a1
join movie_cast m2 on
a1.act_id = m2.act_id
join movies m3
on m2.mov_id = m3.mov_id
where m3.mov_year >= 2015);

select m.mov_title, max(r.rev_stars)
from movies m, rating r
where m.mov_id = r.mov_id
and m.mov_id in
(select mov_id from rating where rev_stars > 0 group by mov_id having count(rev_stars) > 0)
group by m.mov_title
order by m.mov_title;

update rating
	set rev_stars = 5
	where mov_id in (select mov_id from movies where dir_id in (select dir_id from director where dir_name = 'hitchcock'));