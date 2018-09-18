program qq;
type mass=array[0..1000,1..2] of real;
var i,j,n:integer;
    a:mass;
begin
  readln(a[0,2]);
  rewrite(output,'C:\PABCWork.NET\0\Новый текстовый документ.txt');
  for n:=1 to 500 do
  begin
    a[0,1]:=1;
    for i:=1 to n do
    begin
     a[i,2]:=1;
    end;
    i:=0;
    repeat
      if a[i,1]+a[i,1]<n
      then begin
             i:=i+1; 
             a[i,1]:=a[i-1,1]+a[i-1,1];
             a[i,2]:=a[i-1,2]*a[i-1,2];
           end
      else begin
             for j:=i downto 0 do
             begin
               if a[i,1]+a[j,1]<=n
               then begin
                      i:=i+1;
                      a[i,1]:=a[i-1,1]+a[j,1];
                      a[i,2]:=a[i-1,2]*a[j,2];
                    end;
             end;
           end;
    until n=a[i,1];
    
    writeln(i);
  end;
  
  close(output);
end.
