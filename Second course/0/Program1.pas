program qq;
 var s,q,a,n,m:integer;
begin
  write('������� ����� ');
  readln(a);
  write('������� ������� ');
  readln(n);

rewrite(output,'C:\PABCWork.NET\0\����� ��������� ��������(2).txt');
for m:=1 to 500 do
  begin
  s:=1;
  q:=0;
  while n<>0 do
   begin
    if odd(n)= true then
     begin
      s:=s*a;
      inc(q);
     end;
    if n shr 1 <>0 then
      begin
       a:=a*a;
       inc(q);
      end;
     n:=n shr 1;
    end;
      writeln('��������� ',s);
      writeln('���������� ��������� ',q);
 end;
  close(output);

    end.
      