program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b:array [0..110] of integer;
   i,j,n,x,p:integer;
begin
   for i:=0 to 110 do
      begin
         a[i]:=0;
         b[i]:=0;
      end;
   read(n);
   for i:=1 to n do
      begin
         read(x);
         inc(a[x]);
      end;
   read(n);
   for i:=1 to n do
      begin
         read(x);
         inc(b[x]);
      end;
   p:=0;
   for i:=1 to 110 do
      for j:=i-1 to i+1 do
         if (a[i]>0) and (b[j]>0) then
            begin
               if (a[i]>b[j]) then
                  begin
                     a[i]:=a[i]-b[j];
                     p:=p+b[j];
                     b[j]:=0;
                  end
               else
                  begin
                     b[j]:=b[j]-a[i];
                     p:=p+a[i];
                     a[i]:=0;
                  end;
            end;
   writeln(p);
   readln;
   readln;
end.
