program qq;
 var i,p,n,a:integer;
begin
  write('������� ����� ');
  readln(a);
  write('������� ������� ');
  readln(n);
  p:=1;
  for i:=1 to n do
  p:=p*a;
  writeln('��������� ',p);
  end.