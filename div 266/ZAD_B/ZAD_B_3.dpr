program ZAD_B_3;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   sq = 100010;
var
   n,a,b,a1,b1,ax,by,min:int64;
   i:integer;
begin
   readln(n,a,b);
   a1:=(6*n-1) div b+1;
   b1:=(6*n-1) div a+1;
   if (a*b>=6*n) then
      begin
         min:=a*b;
         ax:=a;
         by:=b;
      end
   else if (a1*b<b1*a) then
      begin
         min:=a1*b;
         ax:=a1;
         by:=b;
      end
   else
      begin
         min:=a*b1;
         ax:=a;
         by:=b1;
      end;
   for i:=1 to sq do
      begin
         a1:=a*i;
         b1:=b;
         if (a1*b1>=6*n) then
            begin
               if (a1*b1<min) then
                  begin
                     min:=a1*b1;
                     ax:=a1;
                     by:=b1;
                  end;
            end
         else
            begin
               b1:=(6*n-1) div a1+1;
               if (b1>=b) and (a1*b1<min) then
                  begin
                     min:=a1*b1;
                     ax:=a1;
                     by:=b1;
                  end;
            end;
         //k
         b1:=b*i;
         a1:=a;
         if (a1*b1>=6*n) then
            begin
               if (a1*b1<min) then
                  begin
                     min:=a1*b1;
                     ax:=a1;
                     by:=b1;
                  end;
            end
         else
            begin
               a1:=(6*n-1) div b1+1;
               if (a1>=a) and (a1*b1<min) then
                  begin
                     min:=a1*b1;
                     ax:=a1;
                     by:=b1;
                  end;
            end;
      end;
   writeln(min);
   writeln(ax,' ',by);
   readln;
end.
