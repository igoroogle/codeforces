program ZAD_4;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,a,b,max,p:int64;
   i,j:integer;
begin
   readln(n);
   max:=4444477777;
   for i:=1 to 1023 do
      begin
         a:=0;
         b:=0;
         j:=i;
         p:=0;
         while j>0 do
            begin
               if odd(j) then
                  begin
                     inc(a);
                     p:=p*10+4;
                  end
               else
                  begin
                     inc(b);
                     p:=p*10+7;
                  end;
               j:=j div 2;
            end;
         while (b<a) and (a+b<9) do
            begin
               p:=p*10+7;
               inc(b);
            end;
         if (a=b) and (p>=n) and (p<max) then max:=p;
      end;
   writeln(max);
   readln;
end.
