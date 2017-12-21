open Utils;

open MomentRe;

let component = ReasonReact.statelessComponent("EventListItem");

let make = (~event: EventData.event, _children) => {
  ...component,
  render: (_self) =>
    <li>
      <div> (textEl(event.title)) </div>
      <div> (textEl(event.starts_at |> Moment.format("MMMM D YYYY h:mma Z"))) </div>
      <div> (textEl(event.ends_at |> Moment.format("MMMM D YYYY h:mma Z"))) </div>
    </li>
};
