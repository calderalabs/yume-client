open Utils;

let component = ReasonReact.statelessComponent("AboutUsPage");

let make = (_children) => {...component, render: (_self) => <div> (textEl("About Us")) </div>};
