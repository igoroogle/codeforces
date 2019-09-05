program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   n,m,k,i,x,rt,z,zn:integer;
   sum:array [0..5010] of int64;
   s,ss,max:int64;
begin
   readln(n,k,m);
   sum[0]:=0;
   for i:=1 to n do
      begin
         read(x);
         sum[i]:=sum[i-1]+x;
      end;
   ss:=0;
   rt:=k*m;
   z:=n;
   while rt>0 do
      begin
         max:=sum[rt]-sum[rt-k];
         zn:=rt-k;
         for i:=rt to z do
            begin
               s:=sum[i]-sum[i-k];
               if (s>=max) then
                  begin
                     max:=s;
                     zn:=i-k;
                  end;
            end;
         rt:=rt - k;
         z:=zn;
         ss:=ss+max;
      end;
   writeln(ss);
   readln;
   readln;
end.
