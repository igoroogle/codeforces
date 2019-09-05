program ZAD_6;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   n,i,j,t,k,x,s,kr,x1,y1,a,b:integer;
begin
   readln(n);
   s:=1;
   for i:=1 to 9 do
      begin
         kr:=trunc(power(2,1.0*i));
         for j:=0 to kr-1 do
            begin
               x1:=0;
               y1:=1;
               while y1<=9 do
                  begin
                     t:=j;
                     x:=0;
                     a:=0;
                     b:=0;
                     for k:=1 to i do
                        begin
                           if odd(t) then
                              begin
                                 x:=x*10+y1;
                                 inc(a);
                              end
                           else
                              begin
                                 if (x=0) and (x1=0) then
                                    begin
                                       x:=maxint;
                                       break;
                                    end;
                                 x:=x*10+x1;
                                 inc(b);
                              end;
                           t:=t div 2;
                        end;
                     if (x<n) then inc(s);
                     if (a=0) or (b=0) then
                        begin
                           x1:=x1+2;
                           y1:=x1+1;
                        end
                     else if (y1<9) then y1:=y1+1
                     else
                        begin
                           x1:=x1+1;
                           y1:=x1+1;
                        end;
                  end;
            end;
      end;
   writeln(s);
   readln;
end.
