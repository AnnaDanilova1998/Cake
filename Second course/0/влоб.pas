program qq;
 var i,p,n,a:integer;
begin
  write('¬ведите число ');
  readln(a);
  write('¬ведите степень ');
  readln(n);
  p:=1;
  for i:=1 to n do
  p:=p*a;
  writeln('–езультат ',p);
  end.