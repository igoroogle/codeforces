program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   v1,t1,a1,ind1:array [1..1000010] of integer;
procedure build1(l,r,v:integer);
var
   m:integer;
begin
   if (l=r) then t1[v]:=0
   else
      begin
         m:=(l+r) div 2;
         build(l,m,v+v);
         build(m+1,r,v+v+1);
         t1[v]:=max(t1[v+v],t2[v+v+1]);
      end;
end;
procedure update1(l,r,v,ind:integer);
var
   m:integer;
begin
   if (l=r) then t1[v]:=l
   else
      begin
         m:=(l+r) div 2;
         if (ind<=m) then update1(l,m,v+v,ind)
         else update1(m+1,r,v+v+1,ind);
         t1[v]:=max(t1[v+v],t1[v+v+1]);
      end;
end;
procedure build1(l,r,v:integer);
var
   m:integer;
begin
   if (l=r) then t1[v]:=0
   else
      begin
         m:=(l+r) div 2;
         build(l,m,v+v);
         build(m+1,r,v+v+1);
         t1[v]:=max(t1[v+v],t2[v+v+1]);
      end;
end;
procedure update1(l,r,v,ind:integer);
var
   m:integer;
begin
   if (l=r) then t1[v]:=l
   else
      begin
         m:=(l+r) div 2;
         if (ind<=m) then update1(l,m,v+v,ind)
         else update1(m+1,r,v+v+1,ind);
         t1[v]:=max(t1[v+v],t1[v+v+1]);
      end;
end;
begin
  { TODO -oUser -cConsole Main : Insert code here }
end.
