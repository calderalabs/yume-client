let component = ReasonReact.statelessComponent("Link");

let make = (~route: Routing.route, ~currentRoute: Routing.route, ~href: string, children) => {
  ...component,
  render: (_self) => {
    let activeClass = currentRoute == route ? "active" : "";
    <div> (ReasonReact.createDomElement("a", ~props={"className": activeClass, "href": href}, children)) </div>
  }
};
