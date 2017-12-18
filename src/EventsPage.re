open Utils;

let component = ReasonReact.statelessComponent("EventsPage");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div>
      (textEl("Test"))
    </div>
  }
};
