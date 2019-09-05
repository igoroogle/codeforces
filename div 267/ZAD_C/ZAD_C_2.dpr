program ZAD_C_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   n,m,k,i,j,x:integer;
   sum:array [0..5010] of int64;
   d:array [0..5010,0..5010] of int64;
begin
   readln(n,k,m);
   sum[0]:=0;
   for i:=1 to n do
      begin
         read(x);
         sum[i]:=sum[i-1]+x;
      end;
   for i:=1 to n do
      begin
         d[0,i]:=0;
         d[i,0]:=0;
      end;
   for i:=1 to m do
      for j:=1 to n do
         begin
            if (j-k>0) then
               begin
                  if (d[i-1,j-k]+(sum[j]-sum[j-k])>d[i,j-1]) then
                     d[i,j]:=d[i-1,j-k]+(sum[j]-sum[j-k])
                  else d[i,j]:=d[i,j-1];
               end
            else d[i,j]:=d[i-1,j];
         end;
   writeln(d[m,n]);
   readln;
   readln;
end.
