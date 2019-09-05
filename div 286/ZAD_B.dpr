program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   dl = 210;
   dl2 = 110;
var
   head,list,mas,next:array [1..dl] of integer;
   use,use2:array [1..dl2] of boolean;
   i,j,k,kol,x,y,z,q,n,m:integer;
procedure push(x,y,z:integer);
begin
   inc(kol);
   list[kol]:=y;
   mas[kol]:=z;
   next[kol]:=head[x];
   head[x]:=kol;
end;
procedure dfs(cv,v:integer);
var
   i:integer;
begin
   use2[v]:=false;
   if (v=y) then
      begin
         use[cv]:=true;
         exit;
      end;
   i:=head[v];
   while i<>-1 do
      begin
         if (use2[list[i]]) and (mas[i]=cv) then dfs(cv,list[i]);
         i:=next[i];
      end;
end;
begin
   for i:=1 to dl do
      begin
         head[i]:=-1;
         next[i]:=-1;
      end;
   read(n,m);
   kol:=0;
   for i:=1 to m do
      begin
         read(x,y,z);
         push(x,y,z);
         push(y,x,z);
      end;
   read(q);
   for k:=1 to q do
      begin
         read(x,y);
         for i:=1 to m do use[i]:=false;
         kol:=0;
         i:=head[x];
         while i<>-1 do
            begin
               for j:=1 to n do use2[j]:=true;
               use2[x]:=false;
               dfs(mas[i],list[i]);
               i:=next[i];
            end;
         for i:=1 to m do
            if (use[i]) then inc(kol);
         writeln(kol);
      end;
   readln;
   readln;
end.
